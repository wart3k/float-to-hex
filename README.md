# float-to-hex
Converts float numbers to hex numbers.

## How to use
The values to convert and the converted ones are in the folder converter_files.
The converter first checks the float_dec.txt and then the float_hex.txt file. The conversion is then located in 
the converted.txt file

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

## Future Features

- improvement of output in converted.txt
- input correction for different hex representations (0x12345678, 12345678, 0x12 0x34 0x56 0x78, ...)
- Release build config for less console output
- Unit Tests
- GUI

