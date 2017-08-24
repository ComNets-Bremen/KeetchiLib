# KeetchiLib

![Keetchi logo](https://raw.githubusercontent.com/ComNets-Bremen/KeetchiLib/master/img/keetchi_logo.png)

A C++ implementation of the Organic Data Dissemination (ODD) model


Introduction
------------

The number of computing devices of the IoT are expected to grow exponentially.
To address the communication needs of the IoT, research is being done to
develop new networking architectures and to extend existing architectures. An
area that lacks attention in these efforts is the emphasis on utilisation of
omnipresent local data. There are a number of issues (e.g., underutilisation of
local resources and dependence on cloud based data) that need to be addressed
to exploit the benefits of utilising local data.

The Sustainable Communication Networks group (ComNets) at the University of
Bremen has identified a novel data dissemination model, called the
Organic Data Dissemination (ODD) model to utilise the omni-present data around
us, where devices deployed with the ODD model are able to operate even without
the existence of networking infrastructure. The realisation of the ODD model
requires innovations in many different area including the areas of
opportunistic communications, naming of information, direct peer-to-peer
communications and reinforcement learning.

This software, the KeetchiLib is a C++ implementation of the functionality of
the ODD model. The functionality is implemented as an independent statically
linkable library to be used by any application that uses the ODD model to
communicate. These applications which may be implemented as desktop or
smartphone applications that call the functionality of the KeetchiLib
(i.e., libkeetchi.la) to invoke the ODD operations.

The KeetchiLib is simply a library that is platform independent and all
network related operations are also the responsibility of the applications.

The detailed description of the ODD model is presented in the paper
[A Novel Data Dissemination Model for Organic Data Flows](https://link.springer.com/chapter/10.1007%2F978-3-319-26925-2_18) by A. Foerster et al.


Prerequisites
-------------

### Debian based Linux:

`sudo apt-get install autoconf automake libtool`


### MacOS:

(Using homebrew, brew.sh)

- `brew install autoconf`
- `brew install automake`
- `brew install libtool`

(Using macports)

- `sudo port install autoconf automake libtool`

Compilation
-----------

1. Setup a GCC based development environment including autotools in a OS X
or Linux host

2. Checkout the KeetchiLib code from Github

3. Perform the following commands:
    - `./bootstrap`
    - `./configure`
    - `make`

Create documentation
--------------------

A target for creating doxygen-based documentation is available. Just perform
`make doxygen-doc`. The resulting documents will be located in `doxygen-doc`. 

Additionally, a set of flowcharts and a class diagram of the implementation 
is available in the `docs` folder.


Using libkeetchi.la
-------------------

After executing "`make`", you will find `libkeetchi.la` and `libkeetchi.a` in lib/.libs/

src/testapp contains a simple example app for testing basic functionality.

The functionality of the KeetchiLib is availed through the classes `KLKeetchi`
and `KLAction`. The applications that use the KeetchiLib must instantiate an
object of `KLKeetchi` giving the following parameters.

1. cachePolicy - Cache management policy to be implemented

2. cacheSize - The size of cache in bytes

3. ownAddr - MAC address of the host that instantiates the KLKeetchi object

4. changeSigThreshold - The threshold ratio to determine whether the neighbourhood changes 
are considered as being significant or not (a value between 0.0 and 1.0, inclusive)

5. coolOffDur - The duration to wait when repeated insignificant neighbourhood changes are
received

6. learningConst - The constant used to weight the Goodness values when updating in cache 
(value between 0.0 and 1.0)

Once a `KLKeetchi` object is created, the following general workflow must be followed.

1. Register application using registerApplication() method in `KLKeetchi`.

2. When a data message is generated by the application or is received over the
network interface, pass it to `processDataMsg()` method to process the message
and perform the ODD related activities. The return from this method is a
`KLAction` object which specifies the actions tone taken by the application.

3. When a feedback message is generated by the application or received over
the network interface, call the `processFeedbackMsg()` method to process.

4. The network interface (i.e., the link layer) must send a list of neighbours periodically 
to `processNewNeighbourList()` method.

5. Additionally, the application must periodically call `ageData()` method to
perform the housekeeping activities in the ODD model.


Support
-------

If you have any questions or comments, please write to,

  - Asanga Udugama (adu@comnets.uni-bremen.de),
  - Jens Dede (jd@comnets.uni-bremen.de) or
  - Anna Foerster (anna.foerster@comnets.uni-bremen.de)

