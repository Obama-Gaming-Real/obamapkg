install:
	mkdir -p ~/.obamapkg/packages/
	sudo g++ obamapkg.cpp -o /usr/local/bin/obamapkg -pedantic -Os -s -ffast-math -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables -fmerge-all-constants -fno-math-errno -fno-unroll-loops
