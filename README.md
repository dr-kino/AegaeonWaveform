# aegaeon-waveform
Arbitrary waveform generator, written in C++ and Octave language, for any function generator. For this project, is used as example, the RIGOL DG1022Z - 2 Channel|25MHz|200MSa/s to load the arbitrary waveform, but is possible generate waveforms for other models using data input specification for different models. To modify it, use program option "header-definition".

![DS1Z_QuickPrint3](https://user-images.githubusercontent.com/27175864/66274452-d347e500-e876-11e9-853e-cc0ea43a5dcd.png)

## Waveform Data Example

08 00 00 00 - Number of samples.
01 - Always 0x01.
00 - Always 0x00.
01 - Output mode.
30 30 30 30 2E 52 41 46 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 - File name.
00 00 40 E5 9C 30 12 00 - Period or sample.
40 78 7D 01 - High level value.
C0 87 82 FE - Low level value.
4D B4 - CRC value of the waveform data.
B6 B9 - CRC value of the header.
00 00 00 00 - Always 0x00.
FF BF DA B6 B6 AD 91 A4 6D 9B 48 92 24 89 00 80 - Data samples, 2 bytes each sample (0x0000 to 0x3FFF or 0x8000 to 0xBFFF).

# Build Options

g++ -lboost_program_options aegaeon.cpp -o aegaeon
