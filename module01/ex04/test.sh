make

echo "test1:"
cat test1
./ex04 test1 X Y
echo "after:"
cat test1.replace

echo "\n"

echo "test2:"
cat test2
./ex04 test2 cat world
echo "\n"
echo "after:"
cat test2.replace

echo "test3: (empty)"
cat test3
./ex04 test3 X Y
echo "after:"
cat test3.replace