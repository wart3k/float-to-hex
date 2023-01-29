# float-to-hex
Converts float numbers to hex numbers and vice versa.

## Table of content
* [How to use](#how-to-use)
* [Converting float decimal values to hex values](#converting-float-decimal-values-to-hex-values)
* [Converting float hex values to decimal values](#converting-float-hex-values-to-decimal-values)
* [Output File](#output-file)
* [Used third party tools](#used-third-party-tools)
* [Known Issues](#known-issues) 
* [Future Features](#future-features)

## How to use
The values to convert and the converted ones are in the folder converter_files.
The converter first checks the float_dec.txt and then the float_hex.txt file. The conversion is then located in 
the converted.txt file.

### Converting float decimal values to hex values
To convert decimal float values to their hex equivalent, the decimal numbers should be written under each other 
in the text document converter_files/float_dec.txt. Example:
```Text
-1.5
-1.0
-0.5
0.0
0.5
1.0
1.5
...
```

### Converting float hex values to decimal values
To convert hex float values to their dec equivalent, the hex numbers should be written under each other in the 
text document converter_files/float_hex.txt. Example:
```Text
0xbfc00000
0xbf800000
0xbf000000
0x00000000
0x3f000000
0x3f800000
0x3fc00000
...
```

### Output File
The output file in converted_files/converted.txt with the example values from above should look like this:
```Text
Converted float values into hex values
----------------------------------------------------
0xbfc00000
0xbf800000
...

Converted hex values into float values
----------------------------------------------------
-1.500000
-1.000000
...
```

## Used third party tools
The library used the following third party tools
- For unit tests: [Catch2](https://github.com/catchorg/Catch2)

## Known Issues
- example values that can't be converted with convertHexToFloat
  - Non-numeric strings like "this"
  - values with more than one 0x like "0xbf 0x80 0x00 0x00" or "0xbf0x000x000x00""
  - can´t handle float values like "-1.5"
  - values without 0x at start like "bf000000000"
  - wrong return value for OUT_OF_RANGE values (returns value instead of "NaN")
- example values that can't be converted with convertFloatToHex
  - strings with , like "-1,5"
  - strings with . and , like "-1.0.000.0.00,1213"
  - strings with no value before . or , like ".5" or "-,5"
  - Non-numeric values like "this"
  - correct return value if converter_pair.first is OUT_OF_RANGE or INVALID_ARGUMENT


## Future Features

- input correction for different hex representations (0x12345678, 12345678, 0x12 0x34 0x56 0x78, ...)
- improvement of output in converted.txt
- doxygen doc
- Release build config for less console output
- Unit Tests for all methods
- GUI

