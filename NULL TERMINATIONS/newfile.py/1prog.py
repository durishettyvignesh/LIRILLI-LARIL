"""
1prog.py - simple safe file manipulation demo

This script is placed in:
  NULL TERMINATIONS/newfile.py/1prog.py

It demonstrates basic file operations in a safe, interactive way:
 - create/write a file
 - read a file
 - append to a file
 - show file info (size, exists)
 - optionally rename or delete (requires --yes to perform)

Usage examples (interactive):
  python 1prog.py --demo
  python 1prog.py --write out.txt --text "hello world"
  python 1prog.py --read out.txt

The script is intentionally non-destructive by default. Actions that modify or delete
files require the explicit --yes flag.
"""

from __future__ import annotations

import argparse
import os
from pathlib import Path
import sys
import time


def write_file(path: Path, text: str, overwrite: bool = False) -> Path:
	mode = "w" if overwrite else "x"
	try:
		with path.open(mode, encoding="utf-8") as f:
			f.write(text)
		return path
	except FileExistsError:
		raise


def append_file(path: Path, text: str) -> Path:
	with path.open("a", encoding="utf-8") as f:
		f.write(text)
	return path


def read_file(path: Path) -> str:
	with path.open("r", encoding="utf-8") as f:
		return f.read()
	with path.open("rb") as f:
        return f.read().decode("utf-8", errors="replace")
	


def info(path: Path) -> dict:
	return {
		"exists": path.exists(),
		"size": path.stat().st_size if path.exists() else None,
		"modified": time.ctime(path.stat().st_mtime) if path.exists() else None,
	}


def safe_rename(src: Path, dst: Path, force: bool = False) -> Path:
	if dst.exists() and not force:
		raise FileExistsError(f"Destination {dst} already exists")
	src.replace(dst)
	return dst


def safe_delete(path: Path) -> None:
	path.unlink()


def demo(base: Path) -> None:
	print("Running demo in:", base)
	base.mkdir(parents=True, exist_ok=True)
	f = base / "example.txt"
	if f.exists():
		print("Cleaning up existing demo file")
		try:
			f.unlink()
		except Exception:
			pass

	print("Writing a file using write_file() (non-overwrite)")
	try:
		write_file(f, "First line.\n")
	except FileExistsError:
		print("File already existed")

	print("Appending two lines")
	append_file(f, "Second line.\nThird line.\n")

	print("Reading file contents:")
	print(read_file(f))

	print("File info:")
	print(info(f))


def parse_args(argv: list[str]) -> argparse.Namespace:
	p = argparse.ArgumentParser(description="Simple safe file manipulation demo")
	p.add_argument("--demo", action="store_true", help="Run an interactive demo in ./demo_dir")
	p.add_argument("--write", type=str, help="Write a new file (fails if exists)")
	p.add_argument("--overwrite", action="store_true", help="Allow overwriting when used with --write")
	p.add_argument("--append", type=str, help="Append text to a file path")
	p.add_argument("--text", type=str, default="", help="Text to write or append")
	p.add_argument("--read", type=str, help="Read and print a file")
	p.add_argument("--info", type=str, help="Show info about a file")
	p.add_argument("--rename", nargs=2, metavar=("SRC", "DST"), help="Rename SRC to DST (requires --yes)")
	p.add_argument("--delete", type=str, help="Delete a file (requires --yes)")
	p.add_argument("--yes", action="store_true", help="Confirm destructive actions")
	return p.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
	argv = argv if argv is not None else sys.argv[1:]
	args = parse_args(argv)

	try:
		if args.demo:
			demo(Path("./demo_dir"))
			return 0

		if args.write:
			target = Path(args.write)
			try:
				write_file(target, args.text, overwrite=args.overwrite)
				print(f"Wrote to {target}")
			except FileExistsError:
				print(f"Error: {target} already exists. Use --overwrite to overwrite.")
				return 2

		if args.append:
			append_file(Path(args.append), args.text)
			print(f"Appended to {args.append}")

		if args.read:
			content = read_file(Path(args.read))
			print(content)

		if args.info:
			print(info(Path(args.info)))

		if args.rename:
			if not args.yes:
				print("Rename is destructive. Pass --yes to confirm.")
				return 3
			src, dst = map(Path, args.rename)
			safe_rename(src, dst, force=args.yes)
			print(f"Renamed {src} -> {dst}")

		if args.delete:
			if not args.yes:
				print("Delete is destructive. Pass --yes to confirm.")
				return 4
			safe_delete(Path(args.delete))
			print(f"Deleted {args.delete}")

		return 0
	except Exception as e:
		print("Error:", e)
		return 1


if __name__ == "__main__":
	raise SystemExit(main())
