# About
This repo is for a "code assignment".  
"Specs" are not included in this README to make it less visible.

## Usage
Implement the interface TemperatureRegulationInterface as describer in the header.  
Create an instance of it.  
Pass it to the constructor of TemperatureRegulationInterface.  
Call the method regulateTemperature.  

## Choosen implementation vs specs
The cmake file is for the whole source, including test, the intention is probably that it should be for the business component/module.
Practically it makes most sence to have a everything in the header, especially if performance is important.

We could also imagine the component polling for temperature (With interface for polling also passed in)

A better implementation could be to pass function pointers - then you could have different behaviour according to what is passed in
(Stop methods like StopHeat, StopAll etc) One interface class is choosen partly because the constrait of testing with gmock.

## About resouce constraints
THe footprint of the module is quite minimal, as everything is in the header, and no libraries are pulled in by default.
(Smart pointers etc can stil be used, but it is not mandatory or default).

For this reason there is also no provisions for concurrency (This can easily be implemented by the client)

The floating number type is a template argument so a perfomant type can be choosen, or perhaps a type for decimal numbers.




