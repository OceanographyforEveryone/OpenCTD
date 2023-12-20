Build your own research-quality oceanographic instrument for a fraction of the cost of commercial alternatives. 

Let's explore the ocean, together. 

**Updated 12/20/2023**

# OpenCTD: Oceanography for Everyone

The [OpenCTD Construction and
Operation](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Documentation/Manual)
manual provides a comprehensive, step-by-step guide to building your own
OpenCTD, with a standard construction pathway as well as numerous alternatives
depending on parts availability and technical skills. 

The OpenCTD [core software](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Software) is designed
to be used with an M0-style Arduino microcontroller, for which we recommend the
[Adafruit Adalogger Feather M0](https://www.adafruit.com/product/2796). 

---

There is something radical about making and using your own scientific
instruments. The structure of scientific inquiry has coalesced around a model
that is, in general, both expensive and exclusive. This centralizes knowledge
production within a small circle of individuals, organizations, and
institutions who have access to substantial financial resources. This circle
rarely reflects the breadth of identities, experiences, and ways of knowing
that are most directly connected to the places being explored.

By building your own instruments to study and understand the natural world, you
are expanding the circle of knowledge production. A scientist who can make
their own instruments is not beholden to the cycles of funding and access that
constrain formal, institutional inquiry. A researcher who can build and repair
their own equipment is not dependent on the whims of academic sentiment to
decide what is and is not worthy of study. A community leader who has the tools
to create their own data does not have to wait for institutions to take notice
of an emerging crisis before taking action.

![The OpenCTD](Documentation/Images/IMG_20190727_150858%20(2).jpg)

**You don’t need to ask for permission to understand your world.**

Nowhere is this inequality of access more pronounced than in the ocean
sciences, where all but a few entities have the capital to mount major
oceanographic research campaigns. Even localized coastal research can be
thwarted by lack of access to vessels, equipment, and instruments. As the need
to understand the dramatic changes at the surface and beneath the waves
accelerates, baring the participation of ocean stakeholders erodes our
power to understand, anticipate, and mitigate those changes.

The ocean belongs to everyone. The tools to study the ocean should be
accessible to anyone with the curiosity and motivation to pursue that inquiry.
Chief among these tools is the workhorse of oceanography, the CTD, an
instrument that measures salinity, temperature, and depth. By these
characteristics, scientists can begin to unlock ocean patterns hidden beneath
the sea's surface.

CTDs come in a variety of shapes, sizes, and applications. Most oceanographic
research vessels have a CTD connected to a rosette platform, which houses other
instruments and collects water samples in parallel with real-time data. CTDs
are also commonly attached to fixed moorings, autonomous underwater vehicles
(AUVs), remote-operated vehicles (ROVs), and even to marine animals.

Unfortunately, commercial CTDs are expensive. The most affordable models cost
several thousand dollars. For near-shore oceanographic research on the
relatively shallow continental shelf, this cost can be prohibitive. This
effectively excludes formal researchers from low and middle income countries,
and small island states. Even in high-income countries, formal researchers at
teaching institutions or at early career stages may also find themselves priced
out of ocean research. Informal researchers such as citizen oceanographers,
educators, conservation and management practitioners and students of all levels
face severe challenges accessing expensive scientific instruments. 

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

The OpenCTD is designed to be built by the end-user, providing both access to
the tools of oceanography as well as the skills to maintain, repair, and
replace OpenCTDs. For scientists working in remote settings, the repairability
of the OpenCTD is intended to prevent equipment failures from spiraling into
project failures. For educators seeking novel, in-depth, hands-on STEM
experience for advanced students, the process of building an OpenCTD offers an
introduction to coding, 3D-printing, hardware prototyping, and electronics.
Construction of an OpenCTD can provide a practical foundation for courses in
oceanography and marine or environmental science. 

### Core Resources

The [OpenCTD Construction and
Operation](https://github.com/OceanographyforEveryone/OpenCTD/tree/main/Documentation/Manual)
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

**Updated 12/20/2023**
