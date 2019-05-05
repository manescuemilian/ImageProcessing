#include <stdio.h>
#include <string.h>
#include <vips/vips.h>

int main(int argc, char *argv[]) {
	VipsImage *in, *out;
	double out_height = 150, out_width = 150, height, width;
	if(argc != 3) {
		fprintf(stderr, "Wrong arguments. Try: %s input_file output_file\n", argv[0]);
	}

	if(VIPS_INIT(argv[0])) {
		vips_error_exit(NULL); 
	}

	if(vips_svgload(argv[1], &in, NULL)) {
		vips_error_exit(NULL);
	}	

	width = vips_image_get_width(in);
	height = vips_image_get_height(in);
	double scale = out_width / width, vscale = out_height / height;
	vips_resize(in, &out, scale, vscale, NULL);

	vips_magicksave(out, argv[2], NULL);
	
	vips_shutdown();
}