# OpenCTD Rev8 is here!

**The ocean belongs to everyone.** The tools to study the ocean should be accessible to anyone with the curiosity and motivation to pursue that inquiry. Build your own [research-quality oceanographic instrument](https://tos.org/oceanography/article/the-openctd-a-low-cost-open-source-ctd-for-collecting-baseline-oceanographic-data-in-coastal-waters) and let's explore the ocean, together. 

# OpenCTD: Oceanography for Everyone

The CTD is an oveanographic instrument that measures salinity, temperature, and depth. By measuring these
characteristics, scientists can begin to unlock ocean patterns hidden beneath the sea's surface.

CTDs come in a variety of shapes, sizes, and applications. Most oceanographic research vessels have a CTD connected to a rosette platform, which houses other instruments and collects water samples in parallel with real-time data. CTDs are also commonly attached to fixed moorings, autonomous underwater vehicles (AUVs), remote-operated vehicles (ROVs), and even to marine animals.

Unfortunately, commercial CTDs are expensive. The most affordable models cost several thousand dollars. For near-shore oceanographic research on the relatively shallow continental shelf, this cost can be prohibitive. This
effectively excludes formal researchers from low and middle income countries, and small island states. Even in high-income countries, formal researchers at teaching institutions or at early career stages may also find themselves priced out of ocean research. Informal researchers such as citizen oceanographers, educators, conservation and management practitioners and students of all levels face severe challenges accessing expensive scientific instruments. 

**You don’t need to ask for permission to understand your world.**

By building your own instruments to study and understand the natural world, you are expanding the circle of knowledge production. A scientist who can make their own instruments is not beholden to the cycles of funding and access that constrain formal, institutional inquiry. A researcher who can build and repair their own equipment is not dependent on the whims of academic sentiment to decide what is and is not worthy of study. A community leader who has the tools to create their own data does not have to wait for institutions to take notice
of an emerging crisis before taking action. 

![The OpenCTD](Documentation/Images/IMG_20190727_150858%20(2).jpg)

### Build Your Own CTD

The OpenCTD is a low-cost, open-source CTD designed for budget-restricted
scientists, educators, and researchers working in nearshore coastal ecosystems.
In these waterways, entire research projects can be conducted for less than the
cost of a commercial CTD. OpenCTD was developed by a core team of marine
ecologists in collaboration with a community of scientists, engineers, makers,
and conservation practitioners from around the world. It is assembled from
components commonly available at large hardware stores or through major online
retailers. An Arduino-based microcontroller controls an array of sensors sealed
within a PVC pipe. Power is provided by a standard 3.7V lithium polymer battery
and data are stored in a tab-delimited text file accessed via SD card.  All
OpenCTD software is released open source with no restrictions on use. 

The OpenCTD built by the end-user, providing both access to
the tools of oceanography as well as the skills to maintain, repair, and
replace OpenCTDs. For scientists working in remote settings, the repairability
of the OpenCTD is intended to prevent equipment failures from spiraling into
project failures. For educators seeking novel, in-depth, hands-on STEM
experience for advanced students, the process of building an OpenCTD offers an
introduction to coding, 3D-printing, hardware prototyping, and electronics.
Construction of an OpenCTD can provide a practical foundation for courses in
oceanography and marine or environmental science. 

# Visit [Oceanography for Everyone](http://oceanographyforeveryone.com/) to learn more, inquire about workshops, or purchase OpenCTD kits!

### Publications

Thaler, A., S.K. Sturdivant, R.Y. Neches, and J.J. Levenson. 2024. [The OpenCTD: A low-cost, open-source CTD for collecting baseline oceanographic data in coastal waters](https://tos.org/oceanography/article/the-openctd-a-low-cost-open-source-ctd-for-collecting-baseline-oceanographic-data-in-coastal-waters#citation). Oceanography 37(2):167–173, https://doi.org/10.5670/oceanog.2024.602.

### Core Resources

The [OpenCTD Construction and
Operation](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Documentation)
manual provides a comprehensive, step-by-step guide to building your own
OpenCTD, with a standard construction pathway as well as numerous alternatives
depending on parts availability and technical skills. A shorter manual covering just the calibration process is also available. 

The OpenCTD [core software](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software) is designed
to be used with an M0-style Arduino microcontroller, for which we recommend the
[Adafruit Adalogger Feather M0](https://www.adafruit.com/product/2796). 

You can find all the Arduino libraries as described in the manual, as well as
software for calibrating the conductivity sensors in
[Support](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software/Support).

Hardware file for both 3D printable components and the control unit PBC can be found in [Hardware](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Hardware)
