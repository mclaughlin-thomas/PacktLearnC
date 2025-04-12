# Chapter 8
# Creating and Using Enumerations

C provides various mechanisms for custom and complex data types.

Enumerated Types. These are named values grouped because of some conceptual relationship we want to give them.

## Defining Enumerations

The advantage of the enumeration is that we make our intention of the relationship between the enumerated types explicit.

Two kinds of enumerations, named and unnamed, or anonymous.

Syntax named enumeration 

enum name { enumerationItem1,enumerationItem2, … ,enumerationItemN };

enum suit { eSpade , eHeart , eDiamond , eClub };

or 

enum suit {

    eSpade ,

    eHeart ,

    eDiamond ,

    eClub

};

We have just created a new data type, enum suit!

Any variable of the enum suit may take one of those four possible enumerated constant values.

The convenience of this new type is that we no longer have to remember what each numerical value means; the enumerated item name tells us that.

enum suit {

 eSpade = 4,

 eHeart = 3,

 eDiamond = 2,

 eClub = 1

 };


 -----------
 Example enum w goto label

 int shapeFunc( enum shape )
{
    ...
    if( shape == triangle ) ...
    else if( shape == rectangle ) ...
    else if( shape == circle ) ...
    else{
    goto error:
    }
    ...
    return 0; // Normal end.
error:
    ... // Error: unhandled enumerated type.
    // Clean up, alert user, exit.
    return -1; // Some error value.
}

