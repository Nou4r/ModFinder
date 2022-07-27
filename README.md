# ModFinder

ModFinder is one of my first useful C++ applications that I've developed that would get occasional use. It took me a decent amount of time to create, but I am currently quite satisfied with the result. The purpose of ModFinder is to detect memory regions that are injected via the manual-map method. (The program is unfortunately only compatible with x86 processes. (x64 Implementation is planned in the future and should be extremely simple to implement.)

Typically, the only addresses you will receive are from manual-mapping flags. Rarely, you may receive a few other results of false catches. These are usually very easy to distinguish from the region you're actually looking for. An upside to ModFinder is that even if the entire optional headers page is erased, you will still be informed of regions that correspond with the first region. The primary reason that ModFinder distinguishes from other manual-map detection programs, is due to how well it performs at detecting regions which were mapped.

Unknowncheats thread

- https://www.unknowncheats.me/forum/anti-cheat-bypass/508290-modfinder-tool-locating-mapped-memory.html

The following injectors have been tested and have successfully been detected:
- Extreme Injector (Latest)
- Xenos (Latest)
- Memject (Latest)
- AlisaAlis (Latest)


# Features
- Mapped memory region enumeration.
- Valid DOS header enumeration.

# Compatible
- Windows 10 (64-bit)
- Windows 10 (32-bit)
- Every Windows version before or after 10 has not been tested, but should cause no issues.


# To Do

- Ignore natively loaded dll base addresses.
- Check for dll manifest string.
- Support for x64 processes.
- Possible code improvements. (if needed)

# Image
![mCv8K4G](https://user-images.githubusercontent.com/110091391/181204720-87e00aa4-f890-4e10-9cb6-b393924232d7.png)

