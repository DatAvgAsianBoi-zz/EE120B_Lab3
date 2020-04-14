# Test file for "Lab3_BitManip"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly,
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


# Add tests below

test "PINA: 0x00, PINB: 0x00 => PORTC: 0x00"
setPINA 0x00
setPINB 0x00
Continue 2
expect PORTC 0x00
checkResult

test "PINA: 0xF0, PINB: 0x0F => PORTC: 0x08"
setPINA 0xF0
setPINB 0x0F
Continue 2
expect PORTC 0x08
checkResult

test "PINA: 0xF0, PINB: 0xF0 => PORTC: 0x08"
setPINA 0xF0
setPINB 0xF0
Continue 2
expect PORTC 0x08
checkResult

test "PINA: 0x00, PINB: 0xF0 => PORTC: 0x04"
setPINA 0x00
setPINB 0xF0
Continue 2
expect PORTC 0x04
checkResult

test "PINA: 0xFF, PINB: 0xFF => PORTC: 0x10"
setPINA 0xFF
setPINB 0xFF
Continue 2
expect PORTC 0x10
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
