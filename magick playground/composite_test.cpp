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
	string fileNameFullPath1 = "test.png";
	string fileNameFullPath2 = "test_helper.png";

	try {
		Image image("3072x760", "white");
		Image image1, image2;
		image1.read(fileNameFullPath1);
		image2.read(fileNameFullPath2);
	
		image.composite(image1, 0, 0);
		image.composite(image2, 1536, 0);
			
		image.write("test_composite.png");
		
	} catch(std::exception const& e){
		cout << "There was an error while opening the file : "<< endl;
		cout << e.what() << endl;
	}

	return 0;
}
