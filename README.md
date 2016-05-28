# QTFFmpegWrapper

QT wrapper classes for FFmpeg.

## Dependencies

- FFmpeg libraries
- Qt 5 (may or may not work with earlier versions)

## Setup

1. Create a QT project in the usual way
2. Copy the directory QTFFmpegWrapper into your project
3. Make the following changes to your project .pro file:
 - copy at the end the content of config.pro,
 - and modify the path for the QTFFmpegWrapper directory, the FFmpeg import libraries, and the FFmpeg includes
4. Make sure the FFmpeg dynamic link libraries are available in your path - otherwise the program will crash upon start

### Notes for Unix based systems
The FFmpeg import libraries and FFmpeg includes are in their usual locations - these path may be left empty in the .pro file. Also, the FFmpeg dynamic link libaries are likely already in the path.

### Notes for Windows
FFmpeg library builds for Windows can be found at [zeranoe ffmpeg builds](http://ffmpeg.zeranoe.com/builds).

### Additional help
For additional assistance look at our example projects under examples or [open an issue](https://github.com/scribblemaniac/qtffmpegwrapper/issues/new).