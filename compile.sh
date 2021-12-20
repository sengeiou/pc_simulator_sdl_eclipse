

if [ "$1" = "clean" ]
then
rm -rf build
echo "clean build"
fi
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j
cd ..

