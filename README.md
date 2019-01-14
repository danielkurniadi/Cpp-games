# C++ Games
This is a repository for C++ program that is meant for fun and games. These projects are mostly backbones of a game and for the purpose of demonstration, the output will be displayed in standard terminal. These programs can be used as a backend for real games (but idk why would you...). 

## What are included
- [BullCow Game](https://en.wikipedia.org/wiki/Bulls_and_Cows)
- [Galperin Bounce](https://calculus7.org/2012/03/14/galperins-billiard-method-of-computing-pi/)
- many more coming...

## Naming Conventions
- U – UObject derrived class, i.e. UTexture

- A – AActor derrived class, i.e. AGameMode

- F – All other classes and structs, i.e. FName, FVector

- T – Template, i.e. TArray, TMap, TQueue

- I – Interface class, i.e. ITransaction

- E – Enumeration type, i.e. ESelectionMode

- b – Boolean value, i.e. bEnabled

Typedefs should be prefixed by whatever is appropriate for that type: F if it's a typedef of a struct, U if it's a typedef of a UObject and so on.
Example: 
``` 
typedef TArray<FMytype> FArrayOfMyTypes;
```

