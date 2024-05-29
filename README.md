**GifMaker-OpenCV**

**Description:**
GifMaker-OpenCV is a simple command-line tool developed in C language using the OpenCV library. It allows users to create GIF animations from a sequence of images. This tool utilizes the powerful image processing capabilities of OpenCV to manipulate and combine images into a single animated GIF.

**Features:**
- Create GIF animations from a sequence of images.
- Specify the frame rate and duration of the GIF.
- Supports various image formats such as JPEG, PNG, BMP, etc.
- Simple command-line interface for ease of use.

**Requirements:**
- C compiler (e.g., GCC)
- OpenCV library

**Installation:**
1. Ensure you have a C compiler installed on your system.
2. Install OpenCV library. You can find installation instructions on the OpenCV website: [OpenCV Installation](https://opencv.org/releases/).
3. Clone or download the GifMaker-OpenCV repository.
4. Compile the source code using the provided Makefile or by manually running the compiler command.

**Usage:**
1. Place all the images you want to include in the GIF in a single directory.
2. Open a terminal window and navigate to the directory containing the images.
3. Run the GifMaker-OpenCV executable with the appropriate command-line arguments:
```
./GifMaker-OpenCV [options]
```
Replace `[options]` with the desired parameters such as input directory, output filename, frame rate, etc. Refer to the command-line options section for more details.
