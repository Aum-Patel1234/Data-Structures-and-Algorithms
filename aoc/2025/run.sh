#!/bin/bash
set -e

if [ $# -lt 1 ]; then
  echo "Usage: $0 <source_file> [program_args...]"
  exit 1
fi

if [ -f .env ]; then
  source .env
  export session
fi

echo "$session"
SOURCE="$1"
shift

OUTPUT="${SOURCE%.*}"

gcc "$SOURCE" -lcurl -o "$OUTPUT"

if [ $? -ne 0 ]; then
  echo "Compilation failed.\n"
  exit 1
fi

./"$OUTPUT" "$@\n"
