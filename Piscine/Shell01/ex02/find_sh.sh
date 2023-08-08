find . -type f -name "*.sh" -print | sed 's/\.sh$//' | xargs -n 1 basename
