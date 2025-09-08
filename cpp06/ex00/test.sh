#!/bin/bash
echo "=== CHAR TESTS ==="
./convert 'a' && echo "---"
./convert 'Z' && echo "---" 
./convert '5' && echo "---"
./convert '*' && echo "---"

echo -e "\n=== INT TESTS ==="
./convert 0 && echo "---"
./convert 42 && echo "---"
./convert -42 && echo "---"
./convert +42 && echo "---"
./convert 2147483647 && echo "---"  # INT_MAX
./convert -2147483648 && echo "---" # INT_MIN

echo -e "\n=== FLOAT TESTS ==="
./convert 42.0f && echo "---"
./convert -4.2f && echo "---"
./convert 0.0f && echo "---"
./convert +inff && echo "---"
./convert -inff && echo "---"
./convert nanf && echo "---"

echo -e "\n=== DOUBLE TESTS ==="
./convert 42.0 && echo "---"
./convert -4.2 && echo "---"
./convert 0.0 && echo "---"
./convert +inf && echo "---"
./convert -inf && echo "---"
./convert nan && echo "---"

echo -e "\n=== EDGE CASES ==="
./convert 255 && echo "---"  # Max displayable char
./convert 256 && echo "---"  # Out of char range
./convert 31 && echo "---"   # Non-displayable char
./convert 127 && echo "---"  # DEL character (non-displayable)

echo -e "\n=== INVALID CASES ==="
./convert abc && echo "---"
./convert 42.5.3 && echo "---"
./convert 42f.0 && echo "---"
./convert "" && echo "---"
./convert hello && echo "---"