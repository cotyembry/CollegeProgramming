//Purpose of Program: When a blue object is in view of the camera, the robot will search for a red onject
int main(void) {
	int r, c, i;
	const unsigned char *img;
	camera_open;
	camera_update();
	img=get_camera_frame();
	for(r=0; r<120; r++) {
		for(c=0;c<160;c++) {
			i=3*(160*r + c); // index of pixel to paint into row r, column c
			 graphics_pixel(c,r,img[i+2],img[i+1],img[i]);
	}
}
	graphics_update();
//C
}
