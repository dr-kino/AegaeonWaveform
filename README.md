# aegaeon-waveform
Arbitrary waveform generator, written in C++ and Octave language, for any function generator. For this project, is used as example, the RIGOL DG1022Z - 2 Channel|25MHz|200MSa/s to load the arbitrary waveform, but is possible generate waveforms for other models using data input specification for different models. To modify it, use program option "header-definition".

![DS1Z_QuickPrint3](https://user-images.githubusercontent.com/27175864/66274452-d347e500-e876-11e9-853e-cc0ea43a5dcd.png)

# Build Options

g++ -lboost_program_options aegaeon.cpp -o aegaeon
