# About
This repo is for a "code assignment".  
*"Specs"* are not included in this README to make the repository less visible.

## Usage
Implement the interface TemperatureRegulationInterface as describer in the header.  
Create an instance of it.  Pass it to the constructor of TemperatureRegulationInterface.  
`TemperatureControl<> tc(&contr, 18, 22);`

Call the method `regulateTemperature`.  
`tc.regulateTemperature(23);`  

## Interpretations 
The *specs* are quite limited, though using *gmock* implies an interface or something external to th component "(the word *component*" also implies plugging something in.).
`regulateTemperature` could also have been in an interface,or heating/cooling could have been seperate interfaces.

The cmake file is for the whole source, including test, the intention is probably that it should be for the business component/module.
Practically it makes most sence to have a everything in the header, especially if performance is important.

## About resouce constraints
THe footprint of the module is quite minimal, as everything is in the header, and no libraries are pulled in by default.  For this reason we are not using `std:exception` and typetraits.  
(Smart pointers etc can stil be used, but it is not mandatory or default).

For this reason there is also no provisions for concurrency (This can easily be implemented by the client)

The floating number type is a template argument so a perfomant type can be choosen, or perhaps a type for decimal numbers.




