CC = gcc
CFLAGS = -g -Wall -Wextra
PACKAGE = `pkg-config vips --cflags --libs`
EXEC = images svgs

images: images.c
	$(CC) $(CFLAGS) images.c $(PACKAGE) -o $@

svgs: svg_image.c
	$(CC) $(CFLAGS) svg_image.c $(PACKAGE) -o $@

run_image: images
	./images ${ARGS}

run_svg: svgs
	./svgs ${ARGS}

clean:
	rm -rf $(EXEC)