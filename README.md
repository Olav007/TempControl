# About
This repo is for a "code assignment".  
"Specs" are not included in this README to make it less visible.

## Implementation vs specs
The cmake file is for the whole source, including test, the intention is probably that it should be for the business component/module.
Practically it makes most sence to have a everything in the header, especially if performance is important.

## About resouce constraints
THe footprint of the module is quite minimal, as everything is in the header, and no libraries are pulled in by default.
(Smart pointers etc can stil be used, but it is not default).

For this reason there is also no provisions for concurrency (This can easily be implemented by the client.




