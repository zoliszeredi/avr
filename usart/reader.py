import serial
import itertools


def main():
    reader = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    lines = (reader.readline() for _ in itertools.count())
    for line in lines:
        print line.strip()


if __name__ == '__main__':
    main()
