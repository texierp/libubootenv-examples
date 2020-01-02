## Build

### CMake

```
$: source /opt/poky/2.7.2/environment-setup-cortexa7t2hf-neon-vfpv4-poky-linux-gnueabi
$: mkdir build
$: cd build
$: cmake ..
```

### Meson

```
$: source /opt/poky/2.7.2/environment-setup-cortexa7t2hf-neon-vfpv4-poky-linux-gnueabi
$: meson build
$: cd build
$: ninja
$: ninja test
$: sudo ninja install
```
