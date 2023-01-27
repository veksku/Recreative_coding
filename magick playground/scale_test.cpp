#include <iostream>
#include <Magick++.h>
#include <cmath>

using namespace std;
using namespace Magick;

int main(int argc, char **argv) {

// In an internet example, I read this two lines are needed.
// 	int main(ssize_t /*argc*/, char ** argv) {
 	InitializeMagick(nullptr);
	int width=1536, height=760;
	float faktor;
	cout << "Unesi faktor" << endl;
	cin >> faktor;
	string fileNameFullPath = "test.png";

	try {
		Image image;
		image.read(fileNameFullPath);
	
		int new_width, new_height;
		new_width = faktor*width;
		new_height = faktor*height;
		image.scale(Magick::Geometry(new_width, new_height, 0, 0));
			
		image.write("test_scale.png");
		
	} catch(std::exception const& e){
		cout << "There was an error while opening the file : "<< endl;
		cout << e.what() << endl;
	}

	return 0;
}
