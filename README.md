OOOCode-Error
=============

An OOOCode module for errors

## Features

- Should expose an interface declaring a toString method
- Should expose a default implementation with a printf style constructor interface

## API

To use the default error class

```C
#include "OOOError.h"

OOOError * pError = OOOConstruct(OOOError, "Error: %s", "Something bad");

O_debug(OOOICall(OOOCast(OOOIError, pError), toString));

OOODestroy(pError);
```

To implement an error class

```C
#include "OOOIError.h"

#define OOOClass MyError
OOODeclare()
	OOOImplements
		OOOImplement(OOOIError)
	OOOImplementsEnd
	OOOExports
	OOOExportsEnd
OOODeclareEnd

OOOPrivateData
OOOPrivateDataEnd

OOODestructor
{
}
OOODestructorEnd

OOOMethod(char *, toString)
{
	return "MY ERROR";
}
OOOMethodEnd

OOOConstructor()
{
	#define OOOInterface OOOIError
	OOOMapVirtuals
		OOOMapVirtual(toString)
	OOOMapVirtualsEnd
	#undef OOOInterface

	OOOMapMethods
	OOOMapMethodsEnd
}
OOOConstructorEnd
#undef OOOClass
```

## Roadmap

- Nothing yet

## Contributing

In lieu of a formal styleguide, take care to maintain the existing coding style. Add unit tests for any new or changed functionality.

## Prerequisites

- OpenTV SDK C2.2 from http://community.opentv.com

## Initialising

This projects references sub-modules so after cloning the repository...

```
git submodule init
git submodule update
```

Then the easiest way to work with the project in the OpenTV IDE...

1. Create a new workspace in the root of the project
1. In the IDE choose **File/Import...**
1. In the resulting dialog choose **General/Existing Projects Into Workspace** and press **Next**
1. Choose the **Select Root Directory:** Radio button and **Browse...** to the root of the project
1. A number of projects may be listed under **Projects**
1. Select the projects in the root, deselect those under the submodules folder and then click **Finish**
1. You should then be able to build the OpenTV projects by choosing **Project/Build All**

After you have built the projects at least once run the test application in the Virtual Set top box by...

1. Choosing the **ErrorFlow** project on the left
1. Pressing the green **Run** button at the top
1. In the resulting dialog choose **Local OpenTV Application** and press **OK**

## Release History
_(Nothing yet)_

## License
Copyright (c) 2012 Peter Halliday  
Licensed under the MIT license.