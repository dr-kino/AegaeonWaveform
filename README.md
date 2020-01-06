# aegaeon-waveform
Arbitrary waveform generator, written in C++ and Octave language, for any function generator. For this project, is used as example, the RIGOL DG1022Z - 2 Channel|25MHz|200MSa/s to load the arbitrary waveform, but is possible generate waveforms for other models using data input specification for different models. To modify it, use program option "header-definition".

![DS1Z_QuickPrint3](https://user-images.githubusercontent.com/27175864/66274452-d347e500-e876-11e9-853e-cc0ea43a5dcd.png)

## Waveform Data Example

Bytes 1~4 : [08 00 00 00] - Number of samples.

Byte 5 : [01] - Always 0x01.

Byte 6 : [00] - Always 0x00.

Byte 7 : [01] - Output mode.

Bytes 8~32 : 30 30 30 30 2E 52 41 46 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 - File name.

Bytes 33~40 : 00 40 E5 9C 30 12 00 00 - Period or sample.

Bytes 41~44 : [40 78 7D 01] - High level value.

Bytes 45~48 : [C0 87 82 FE] - Low level value.

Bytes 49~50 : [4D B4] - CRC value of the waveform data.

Bytes 51~52 : [B6 B9] - CRC value of the header.

Bytes 53~56 : [00 00 00 00] - Always 0x00.

Bytes 57~72 : [FF BF DA B6 B6 AD 91 A4 6D 9B 48 92 24 89 00 80] - Data samples, 2 bytes each sample (Range: 0x0000 to 0x3FFF or 0x8000 to 0xBFFF).

## Reverting The Checksum

To revert the checksum founded in raw file, was used a tool called RevEng (http://reveng.sourceforge.net/). The two command lines below retrieve the check sum present in raw file, bytes 49~50 and 51~52. Notice that retrieved data is swapped.

### Wave Form CRC Command

./reveng -w 16 -p 1021 -i ebcc -c ffbfdab6b6ad91a46d9b489224890080

### Header CRC Command

./reveng -w 16 -p 1021 -i ebcc -c 08000000010001303030302e52414600000000000000000000000000000000000040e59c3012000040787d01c08782fe4db4

# Dependencies

# Build Options

g++ -lboost_program_options aegaeon.cpp -o aegaeon

# Waveform Examples

## Ramp
![Aegaeon-Waveform-01](https://user-images.githubusercontent.com/27175864/66438563-f57f6580-ea24-11e9-92d7-fe995c7062fa.png)

## Sinc

## Usage
```bash
./Aegaeon --type txt --waveform teste.csv --filename teste --generator DG-1022Z
```
