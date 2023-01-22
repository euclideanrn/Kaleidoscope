# if build is not a directory, then create it.
if test ! -d build; then
    mkdir build
fi

# If build is a directory, then remove all files in it.
if test -d build; then
    rm -rf build/*
fi

# Initialize the build directory.
cmake -S . -B build

# Build the project.
cmake --build ./build --target all -- -j 4

# Run tests.
if test -d build/test; then
  cd build/test && ctest && cd ../..
fi