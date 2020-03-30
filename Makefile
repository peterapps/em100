debug:
	emcc --bind -o gen/compiled.js \
	cpp/*.cpp \
	-O3 -s WASM=1

run:
	emrun --no_browser --port 8000 .