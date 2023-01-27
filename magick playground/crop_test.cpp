#include <iostream>
#include <Magick++.h>
#include <cmath>

using namespace std;
using namespace Magick;

int main(int argc, char **argv) {

// In an internet example, I read this two lines are needed.
// 	int main(ssize_t /*argc*/, char ** argv) {
 	InitializeMagick(nullptr);
	double A_x, A_y, B_x, B_y;
	cout << "Unesi A_x" << endl;
	cin >> A_x;
	cout << "Unesi A_y" << endl;
	cin >> A_y;
	cout << "Unesi B_x" << endl;
	cin >> B_x;
	cout << "Unesi B_y" << endl;
	cin >> B_y;
	string fileNameFullPath = "test.png";

	try {
		Image image;
		image.read(fileNameFullPath);
	
		if(A_x > B_x && A_y > B_y) // A gore desno, B dole levo
			image.crop(Geometry(A_x - B_x, A_y - B_y, B_x, B_y)); 
		//(width, height, xOffset, yOffset) Offset je gornja leva tacka
		else if(A_x > B_x && A_y < B_y) // A dole desno, B gore levo
			image.crop(Geometry(A_x - B_x, B_y - A_y, B_x, A_y));
		
		else if(A_x < B_x && A_y > B_y) // A gore levo, B dole desno
			image.crop(Geometry(B_x - A_x, A_y - B_y, A_x, B_y));
		
		else if(A_x < B_x && A_y < B_y) // A dole levo, B gore desno
			image.crop(Geometry(B_x - A_x, B_y - A_y, A_x, A_y));
			
		image.write("test_crop.png");
		// display the image in an X11 window and the program stays here until the window is closed.
		

	} catch(std::exception const& e){
		cout << "There was an error while opening the file : "<< endl;
		cout << e.what() << endl;
	}


	return 0;
}
