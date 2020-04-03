HID Emulated
============

Software that monitors and emulates HID devices.

# Usage

```shell
./hid-emulated
```

# Building

Build and install the project:
```shell
meson bin
ninja -C bin
ninja -C bin install
```

Test the project:
```shell
ninja -C test
```

Generate doc:
```shell
meson bin
ninja -C bin doc
```

# License

This project is licensed under GPL-2.0.

# Author

César `MattGorko` Belley <cesar.belley@lse.epita.fr>
