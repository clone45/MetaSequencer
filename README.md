# MetaSequencer
Firmware for the MetaSequencer module by Microbe Modular

Programming notes:

I'm using the Arduino 1.5.7 build, but I'm not sure if that matters.

1. In the Arduino IDE, under Tools, set your settings to:

    Board: Arduino Nano<br>
    Processor: ATMega328<br>
    Programmers: AVRISP mk2 (yours may differ)

2. Under File/Preferences, turn on verbose output during compilation.

3. Load the code and click the checkbox to Verify/Compile without uploading.

4. Compile the code.  Look in the verbose output, near the bottom, for the location of the .elf file that was generated.  My line looks like this:

    C:\Program Files (x86)\Arduino/hardware/tools/avr/bin/avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 C:\Users\Bret\AppData\Local\Temp\build2617538330943428195.tmp/MetaSequencer.cpp.elf

    The location and filename of the .elf file will stay the same until you restart the Arduino IDE.  So be careful, in the future, not to accidentally use an outdated .elf file, otherwise you'll think to yourself, "What the heck is going on?"

5. Connect your programmer and power up the unit.  If you're using the AVRISP mk2, the stripe should be on the bottom.

6. Download and open up Atmel Studio.  I'm using 6.2.  I'm sure that any version after 6.2 will work.

7. In Atmel Studio, under the Tools menu, select Device Programming

8. If the device is connected, Atmel Studio will automatically recognize it.  Mine says:

    Tool: AVRISP mkII<br>
    Device: ATmega328<br>
    Interface ISP.<br>

    Press the Apply button.

9. On the left menu that appears, select "Memories"

10. Under the Flash section, browse for the .elf file and click Program.

That should do it!

Cheers,
Bret
