# Code Review


## Repository structure

1. Make sure to give a CMakeList.txt file inside of the repository. That way, it would be way easier for another developer to test your code
2. Try to organize you project. I would create folders for header files, c++ source files, external sources, etc...
3. Just a small observation, your file 'Pokemon_vector.hpp' lacks an upper case on 'vector'. It's not consistent with the name of the c++ source file. It's not a big problem but it can make the difference between a good code and a very good code.
4. Instead of '.hpp' files, you could also have used '.h' files for headers, it works exactly the same and this is what is typically done.
5. Instead of putting your tests in the 'main.cpp' and commenting them, you could create test files. That way, you won't need to comment/uncomment each time you want to retest something.
6. The best practice is to have a 'build' folder where you put all of your build files (.o and executables). You need to add this 'build' folder to your .gitignore so that it is not tracked by git. Someone that clones your repo don't want your build files associated with it. It's even more true when they are placed a bit everywhere. 

## Pokemon Class

### Header file

1. When you have a lot of argument in the definition of a function (e.g the constructor), do not hesitate to put them in column instead of line. It is easier to read when all the arguments are aligned. 

### Source file

1. Nothing to say about the Constructor, Copy Constructor, Destructor. Everything's all good.
2. For the doAttack, everything works good. One thing that I would change would be to transform this:
    ```cpp
    if (damage < 0) damage = 0;
    ```
    into this:
    ```cpp
    damage = std::max(damage, 0);
    ```
    I personally think this is a more elegant way of doing the same thing.

    **Note**: you can also use this method for the HitPoint attribute two lines after that.
3. In displayInfo(). I especially love the way you organized your indentation. This is a clever way to keep the code clean, even with so much things to print.

## Pokemon Vector Class

Nothing to say. All good, clear and logical.

## Pokedex Class

### Header file

1. Maybe you should have put the static variable containing the instance of the singleton. I noticed that you create the instance in your source file, but it does not even appear in the class header definition.

    Maybe you could have a class definition like this:
    ```cpp
    class Pokedex : public PokemonVector {
    private:
        static Pokedex instance; //<--This line is important for readability

        Pokedex();
        ~Pokedex();

        Pokedex(const Pokedex&) = delete;
        Pokedex& operator=(const Pokedex&) = delete;
    public:
        static Pokedex& getInstance();
        Pokemon getClonePokemon(int id) const;
    };
    ```


### Source File

1. In the getInstance() method, you could add a verification to see if the instance is not already existing. In your case, if we call getInstance() several time, the instance variable is always overwritten.

2. On these line:
    ```cpp
    20| std::getline(file, line);
    ```
    it would have been great to have a comment saying
    ```cpp
    // skipping the first line of the file, which contains the labels of the columns
    ```
    Otherwise it's a bit hard to know why you do this getLine() and you're not using the line that you got.
3. The data extraction from the csv is ok. However I would advise you to put this code to extract the data in a separate folder. That way you could have an abstraction layer on the csv reading. Your code would be a bit less messier.


## Overall

Your code was working, some minor changes can be made to improve readabilty. But overall it's good. Great work !!!

