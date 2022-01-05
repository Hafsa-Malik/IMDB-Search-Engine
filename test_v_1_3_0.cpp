#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <iterator>
#include <map>
#include <typeinfo>
using namespace std;

template <typename Type>
class ListNode
{
public:
    Type data;
    ListNode *next;
};

//LinkedList data-type declaration
template <typename Type>
class LinkedList
{
public:
    ListNode<Type> *Head;     // special variable which stores address of the head node.
    ListNode<Type> *Tail;     // special variable which stores address of the tail node.
    ListNode<Type> *Loc_;     //to be used by Search(value) method to store address of the node containing the searched value in a list. If it is not found it contains NULL.
    ListNode<Type> *PredLoc_; //to be used by Search(value) method to store address of logical predecessor of value in a list.

    int length;
    //Creating an empty Linked List
    LinkedList()
    {
        Head = NULL;
        Tail = NULL;
        PredLoc_ = NULL;
        Loc_ = NULL;
        length = 0;
    }

    //returns the length of the list
    int getLength() const
    {
        return length;
    }

    // checks whether the list is empty or not. Returns true if empty and false otherwise.
    bool isEmpty()
    {
        return Head == NULL;
    }

    Type valueAtIndex(int value)
    {
        Loc_ = Head;
        int i = 0;
        while (i < value)
        {
            Loc_ = Loc_->next;
            i++;
        }

        return Loc_->data;
    }

    // takes input from a user and inserts it at the front of a list
    void InsertAtFront(Type value)
    {
        ListNode<Type> *newNode = new ListNode<Type>();
        newNode->data = value;
        if (isEmpty())
        {
            Head = newNode;
            Tail = newNode;
            length++;
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
            length++;
        }
    }

    // takes input from a user and inserts it at the tail end of a list
    void InsertAtEnd(Type value)
    {
        ListNode<Type> *newNode = new ListNode<Type>();
        newNode->data = value;
        if (isEmpty())
        {
            Head = newNode;
            Tail = newNode;
            length++;
        }
        else
        {
            Tail->next = newNode;
            Tail = newNode;
            length++;
        }
    }
    //prints the list
    void PrintList()
    {
        if (!isEmpty())
        {
            ListNode<Type> *temp = Head;
            while (temp != NULL)
            {
                cout << temp->data << " | ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }
    //searches a value in list
    bool SearchValue(Type value)
    {
        Loc_ = Head;
        PredLoc_ = NULL;
        if (isEmpty())
        {
            return false;
        }
        while (Loc_ != NULL)
        {
            if (Loc_->data.compare(value) == 0)
            {
                return true;
            }
            Loc_ = Loc_->next;
        };
        //as value is not found so set loc equal to null.
        if (Loc_ != NULL && Loc_->data.compare(value) != 0)
        {
            return false;
        }
    }
    void InsertSorted(Type value)
    {

        Search(value);
        if (Loc_ != NULL)
        {
            cout << "Value already exists" << endl;
        }
        else
        {
            if (PredLoc_ == NULL)
            {
                InsertAtFront(value);
            }
            else
            {
                ListNode<Type> *newNode = new ListNode<Type>();
                length++;
                newNode->data = value;
                newNode->next = PredLoc_->next;
                if (PredLoc_ == Tail)
                {
                    Tail = newNode;
                }
                PredLoc_->next = newNode;
            }
        }
    }
    // searches value and then  deletes it if found.
    void Delete(Type value)
    {
        if (isEmpty())
        {
            return;
        }
        Search(value);
        if (Loc_ != NULL)
        {
            if (PredLoc_ == NULL)
            {
                if (Loc_ == Tail)
                {
                    Head = NULL;
                    Tail = NULL;
                    delete Loc_;
                    length--;
                }
                else
                {
                    Head = Head->next;
                    delete Loc_;
                    length--;
                }
            }
            else
            {
                if (Loc_ == Tail)
                {
                    Tail = PredLoc_;
                    PredLoc_->next = Loc_->next;
                    delete Loc_;
                    length--;
                }
                else
                {
                    //update link using ploc
                    PredLoc_->next = Loc_->next;
                    //finally free memory using delete command.
                    delete Loc_;
                    length--;
                }
            }
        }
        else
        {
            cout << "Value not found. Deletion not possible." << endl;
        }
    }
    void DestroyList()
    {
        while (Head != NULL)
        {
            ListNode<Type> *temp = Head;
            Head = Head->next;
            delete temp;
        }
        Tail = NULL;
        length = 0;
    }

}; //end of LinkedList declaration

class Movie
{
    //Definition of each Field
    string MovieTitle;
    LinkedList<string> genres;
    int TitleYear;
    float IMDB_Score;
    string DirectorName;
    unsigned short int DirectorFbLikes;
    unsigned short int num_critic_for_reviews;
    unsigned short int duration;
    string Actor1Name;
    unsigned short int Actor1FbLikes;
    string Actor2Name;
    unsigned short int Actor2FbLikes;
    string Actor3Name;
    unsigned short int Actor3FbLikes;
    int gross;
    int num_voted_users;
    int cast_total_facebook_likes;
    unsigned short int facenumber_in_poster;
    LinkedList<string> plot_keywords;
    string movie_imdb_link;
    int num_user_for_reviews;
    string language;
    string country;
    string ContentRating;
    int budget;
    float AspectRatio;
    int MovieFbLikes;
    string color;

public:
    //setters for each field
    void setMovieTitle(const string &movieTitle)
    {
        MovieTitle = movieTitle;
    }

    void setGenres(const LinkedList<string> &genres)
    {
        this->genres = genres;
    }

    void setTitleYear(int titleYear)
    {
        TitleYear = titleYear;
    }

    void setImdbScore(float imdbScore)
    {
        IMDB_Score = imdbScore;
    }

    void setDirectorName(const string &directorName)
    {
        DirectorName = directorName;
    }

    void setDirectorFbLikes(unsigned short directorFbLikes)
    {
        DirectorFbLikes = directorFbLikes;
    }

    void setNumCriticForReviews(unsigned short numCriticForReviews)
    {
        num_critic_for_reviews = numCriticForReviews;
    }

    void setDuration(unsigned short duration)
    {
        this->duration = duration;
    }

    void setActor1Name(const string &actor1Name)
    {
        Actor1Name = actor1Name;
    }

    void setActor1FbLikes(unsigned short actor1FbLikes)
    {
        Actor1FbLikes = actor1FbLikes;
    }

    void setActor2Name(const string &actor2Name)
    {
        Actor2Name = actor2Name;
    }

    void setActor2FbLikes(unsigned short actor2FbLikes)
    {
        Actor2FbLikes = actor2FbLikes;
    }

    void setActor3Name(const string &actor3Name)
    {
        Actor3Name = actor3Name;
    }

    void setActor3FbLikes(unsigned short actor3FbLikes)
    {
        Actor3FbLikes = actor3FbLikes;
    }

    void setGross(int gross)
    {
        this->gross = gross;
    }

    void setNumVotedUsers(int numVotedUsers)
    {
        num_voted_users = numVotedUsers;
    }

    void setCastTotalFacebookLikes(int castTotalFacebookLikes)
    {
        cast_total_facebook_likes = castTotalFacebookLikes;
    }

    void setFacenumberInPoster(unsigned short facenumberInPoster)
    {
        facenumber_in_poster = facenumberInPoster;
    }

    void setPlotKeywords(const LinkedList<string> &plotKeywords)
    {
        plot_keywords = plotKeywords;
    }

    void setMovieImdbLink(const string &movieImdbLink)
    {
        movie_imdb_link = movieImdbLink;
    }

    void setNumUserForReviews(int numUserForReviews)
    {
        num_user_for_reviews = numUserForReviews;
    }

    void setLanguage(const string &language)
    {
        Movie::language = language;
    }

    void setCountry(const string &country)
    {
        Movie::country = country;
    }

    void setContentRating(const string &contentRating)
    {
        ContentRating = contentRating;
    }

    void setBudget(int budget)
    {
        Movie::budget = budget;
    }

    void setAspectRatio(float aspectRatio)
    {
        AspectRatio = aspectRatio;
    }

    void setMovieFbLikes(int movieFbLikes)
    {
        MovieFbLikes = movieFbLikes;
    }

    void setColor(string color)
    {
        Movie::color = color;
    }

    //-----------------Getters for each field-----------------------------

    const string &getMovieTitle() const
    {
        return MovieTitle;
    }

    const LinkedList<string> &getGenres() const
    {
        return genres;
    }

    int getTitleYear() const
    {
        return TitleYear;
    }

    float getImdbScore() const
    {
        return IMDB_Score;
    }

    const string &getDirectorName() const
    {
        return DirectorName;
    }

    unsigned short getDirectorFbLikes() const
    {
        return DirectorFbLikes;
    }

    unsigned short getNumCriticForReviews() const
    {
        return num_critic_for_reviews;
    }

    unsigned short getDuration() const
    {
        return duration;
    }

    const string &getActor1Name() const
    {
        return Actor1Name;
    }

    unsigned short getActor1FbLikes() const
    {
        return Actor1FbLikes;
    }

    const string &getActor2Name() const
    {
        return Actor2Name;
    }

    unsigned short getActor2FbLikes() const
    {
        return Actor2FbLikes;
    }

    const string &getActor3Name() const
    {
        return Actor3Name;
    }

    unsigned short getActor3FbLikes() const
    {
        return Actor3FbLikes;
    }

    int getGross() const
    {
        return gross;
    }

    int getNumVotedUsers() const
    {
        return num_voted_users;
    }

    int getCastTotalFacebookLikes() const
    {
        return cast_total_facebook_likes;
    }

    unsigned short getFacenumberInPoster() const
    {
        return facenumber_in_poster;
    }

    const LinkedList<string> &getPlotKeywords() const
    {
        return plot_keywords;
    }

    const string &getMovieImdbLink() const
    {
        return movie_imdb_link;
    }

    int getNumUserForReviews() const
    {
        return num_user_for_reviews;
    }

    const string &getLanguage() const
    {
        return language;
    }

    const string &getCountry() const
    {
        return country;
    }

    const string &getContentRating() const
    {
        return ContentRating;
    }

    int getBudget() const
    {
        return budget;
    }

    float getAspectRatio() const
    {
        return AspectRatio;
    }

    int getMovieFbLikes() const
    {
        return MovieFbLikes;
    }

    const string &getColor() const
    {
        return color;
    }
};

//Movie Class Declaration
class MovieNode
{
public:
    Movie data;      //store data(title,director,actor....etc) of movie
    MovieNode *next; //iterative variable
};

//MovieList Class Declaration
class MovieList
{

public:
    //Default Constructor
    MovieList()
    {
    }
    //Copy Constructor
    MovieList(MovieList const &list)
    {
    }

    //hashmaps decleration
    map<string, MovieList> directorListHashmap;
    map<string, MovieList> actorListHashmap;
    map<string, MovieList> genreHashmap;
    map<string, MovieList> movieNameHashmap;
    map<int, MovieList> movieYearHashmap;

    // thhhe;

    // DirectorList directorListHashmap; //initialize a director list to insert directors in it
    // ActorList actorList;       //initialize an actor list to insert actors in it

    MovieNode *start = NULL;
    MovieNode *last = NULL;

    // takes input from a user and inserts it at the tail end of a list
    void InsertMovie(Movie value)
    {
        MovieNode *newNode = new MovieNode();
        newNode->data = value;
        if (start == NULL)
        {
            start = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }
    //Prints movies titles
    void showMovies()
    {
        
        if (start != NULL)
        {
            MovieNode *temp = start;
            while (temp != NULL)
            {
                cout << temp->data.getMovieTitle() << endl;
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }

    void showMoviesAndRatings()
    {
        if (start != NULL)
        {
            MovieNode *temp = start;
            while (temp != NULL)
            {
                cout << "Movie Name: " << temp->data.getMovieTitle() << endl;
                cout << "Movie Rating: " << temp->data.getImdbScore() << endl;
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }

    //---------------Task2--------------------------------
    void SearchCoActor(string name)
    {
        if (start != NULL)
        {
            MovieNode *temp = start;

            while (temp != NULL)
            {
                cout << "Movie Name: " << temp->data.getMovieTitle() << endl;
                //if actor is actor1 print actor2 and actor3
                if (name.compare(temp->data.getActor1Name()) == 0)
                {
                    cout << "Co-Actors: " << temp->data.getActor2Name() << "," << temp->data.getActor3Name() << endl;
                }
                //if actor is actor2 print actor1 and actor3
                else if (name.compare(temp->data.getActor2Name()) == 0)
                {
                    cout << "Co-Actors: " << temp->data.getActor1Name() << "," << temp->data.getActor3Name() << endl;
                }
                //if actor is actor3 print actor1 and actor2
                else
                {
                    cout << "Co-Actors: " << temp->data.getActor1Name() << "," << temp->data.getActor2Name() << endl;
                }
                temp = temp->next;
            }
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }

    //--------Task3---------------------------
    void SearchUniqueCoActor(string name)
    {

        if (start != NULL)
        {
            LinkedList<MovieNode> movies;
            LinkedList<string> coActors; //create a new string linkedlist to store coacters
            LinkedList<string> MoviesCoActed;
            MovieNode *temp = start;

            while (temp != NULL)
            {
                if (name.compare(temp->data.getActor1Name()) == 0)
                {
                    if (coActors.SearchValue(temp->data.getActor2Name()) == 0)
                    {
                        coActors.InsertAtEnd(temp->data.getActor2Name());
                        MoviesCoActed.InsertAtEnd(temp->data.getMovieTitle());
                    }
                    if (coActors.SearchValue(temp->data.getActor3Name()) == 0)
                    {
                        coActors.InsertAtEnd(temp->data.getActor3Name());
                        MoviesCoActed.InsertAtEnd(temp->data.getMovieTitle());
                    }
                }
                else if (name.compare(temp->data.getActor2Name()) == 0)
                {
                    if (coActors.SearchValue(temp->data.getActor1Name()) == 0)
                    {
                        coActors.InsertAtEnd(temp->data.getActor1Name());
                        MoviesCoActed.InsertAtEnd(temp->data.getMovieTitle());
                    }
                    if (coActors.SearchValue(temp->data.getActor3Name()) == 0)
                    {
                        coActors.InsertAtEnd(temp->data.getActor3Name());
                        MoviesCoActed.InsertAtEnd(temp->data.getMovieTitle());
                    }
                }
                else
                {
                    if (coActors.SearchValue(temp->data.getActor1Name()) == 0)
                    {
                        coActors.InsertAtEnd(temp->data.getActor1Name());
                        MoviesCoActed.InsertAtEnd(temp->data.getMovieTitle());
                    }
                    if (coActors.SearchValue(temp->data.getActor2Name()) == 0)
                    {
                        coActors.InsertAtEnd(temp->data.getActor2Name());
                        MoviesCoActed.InsertAtEnd(temp->data.getMovieTitle());
                    }
                }
                temp = temp->next;
            }
            ListNode<string> *temp2 = MoviesCoActed.Head;
            ListNode<string> *temp3 = coActors.Head;
            while (temp3 != NULL)
            {
                cout << temp3->data << " | " << temp2->data << endl;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }

    //---------------Task4--------------------------------
    void searchCoActorOfCoActors(string name, MovieList &movieList)
    {
        if (movieList.actorListHashmap.count(name) == 0)
            cout << "Actor Not Found V-111" << endl;
        else
        {
            cout << "Found" << endl;
        }
        if (start != NULL)
        {
            MovieNode *temp = start;
            string coactor1, coactor2;

            while (temp != NULL)
            {
                cout << "\n------------------------------------------------------------------" << endl;
                cout << "\t\tMovie Name: " << temp->data.getMovieTitle() << endl;
                cout << "------------------------------------------------------------------" << endl;

                //if actor is actor1 print actor2 and actor3
                if (name.compare(temp->data.getActor1Name()) == 0)
                {
                    coactor1 = temp->data.getActor2Name();
                    coactor2 = temp->data.getActor3Name();
                }
                //if actor is actor2 print actor1 and actor3
                else if (name.compare(temp->data.getActor2Name()) == 0)
                {
                    coactor1 = temp->data.getActor1Name();
                    coactor2 = temp->data.getActor3Name();
                }
                //if actor is actor3 print actor1 and actor2
                else
                {
                    coactor1 = temp->data.getActor1Name();
                    coactor2 = temp->data.getActor2Name();
                }
                cout << "------------------------------------------------------------------" << endl;
                cout << "\t\tCoactor-1: " << coactor1 << endl;
                cout << "------------------------------------------------------------------" << endl;
                cout << "Co-Actors of " << coactor1 << " :-\n"
                     << endl;

                printActorofCoactors(coactor1, movieList);

                cout << "\n------------------------------------------------------------------" << endl;
                cout << "\t\tCoactor-2: " << coactor2 << endl;
                cout << "------------------------------------------------------------------" << endl;
                cout << "Co-Actors of " << coactor2 << " :-\n"
                     << endl;
                printActorofCoactors(coactor2, movieList);
                temp = temp->next;
            }
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }

    //---------------Task 5--------------------------------
    void checkIfCoActor(string name1, string name2)
    {
        if (start != NULL)
        {
            MovieNode *temp = start;

            while (temp != NULL)
            {
                //if actor is actor1 print actor2 and actor3
                if (name1.compare(temp->data.getActor1Name()) == 0)
                {
                    if (name2.compare(temp->data.getActor2Name()) == 0 || name2.compare(temp->data.getActor3Name()) == 0)
                    {
                        cout << name1 << " and " << name2 << " are co-actors in movie \"" << temp->data.getMovieTitle() << "\"." << endl;
                    }
                }
                //if actor is actor2 print actor1 and actor3
                else if (name1.compare(temp->data.getActor2Name()) == 0)
                {
                    if (name2.compare(temp->data.getActor1Name()) == 0 || name2.compare(temp->data.getActor3Name()) == 0)
                    {
                        cout << name1 << " and " << name2 << " are co-actors in movie \"" << temp->data.getMovieTitle() << "\"" << endl;
                    }
                }
                //if actor is actor3 print actor1 and actor2
                else
                {
                    if (name2.compare(temp->data.getActor1Name()) == 0 || name2.compare(temp->data.getActor2Name()) == 0)
                    {
                        cout << name1 << " and " << name2 << " are co-actors in movie \"" << temp->data.getMovieTitle() << "\"" << endl;
                    }
                }
                temp = temp->next;
            }
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }

    void printDirector(string dname)
    {
        if (directorListHashmap.count(dname) == 0)
            cout << "Director Not Found" << endl;
        else
        {
            map<string, MovieList>::iterator directoritr;
            directoritr = directorListHashmap.find(dname);
            directoritr->second.showMovies();
        }
    }

    void printActorMovies(string Actorname)
    {
        if (actorListHashmap.count(Actorname) == 0)
            cout << "Actor Not Found" << endl;
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = actorListHashmap.find(Actorname);
            actoritr->second.showMoviesAndRatings();
        }
    }

    void printActorCoactors(string Actorname)
    {
        if (actorListHashmap.count(Actorname) == 0)
        {
            cout << "Actor Not Found" << endl;
        }
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = actorListHashmap.find(Actorname);
            actoritr->second.SearchCoActor(Actorname);
        }
    }

    void printActorofCoactors(string Actorname, MovieList &movieList)
    {
        if (movieList.actorListHashmap.count(Actorname) == 0)
        {
            cout << "Actor Not Found" << endl;
        }
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = movieList.actorListHashmap.find(Actorname);
            actoritr->second.SearchCoActor(Actorname);
        }
    }

    void printCoactorsOfCoactors(string Actorname, MovieList &movieList)
    {
        int count = 0;
        map<string, MovieList> tempactorListHashmap(actorListHashmap.begin(), actorListHashmap.end());
        map<string, MovieList>::iterator actoritrl;
        cout << "\nThe map gquiz1 is : \n";
        cout << "\tKEY\tELEMENT\n";
        for (actoritrl =    movieList.actorListHashmap.begin(); actoritrl != movieList.actorListHashmap.end(); ++actoritrl)
        {
               if(count>30)
                    break;
                count++;
            cout << '\t' << actoritrl->first << endl;
            actoritrl->second.showMovies();
        }

        //making a temp copy of hashmap to pass on the function
        // assigning the elements from gquiz1 to gquiz2

        if (tempactorListHashmap.count(Actorname) == 0)
            cout << "AAAAA" << endl;
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = actorListHashmap.find(Actorname);
            cout << "LLLLL" << endl;
            actoritr->second.searchCoActorOfCoActors(Actorname, movieList);
        }
    }

    void printCheckIfCoActor(string Actor1, string Actor2)
    {
        if (actorListHashmap.count(Actor1) == 0 && actorListHashmap.count(Actor2) == 0)
            cout << "Actor Not Found" << endl;
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = actorListHashmap.find(Actor1);
            actoritr->second.checkIfCoActor(Actor1, Actor2);
        }
    }

    void printUniqueCoActor(string ActorName)
    {
        string h = "hello";
        if (actorListHashmap.count(ActorName) == 0)
        {
            cout << "Actor Not Found" << endl;
        }
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = actorListHashmap.find(ActorName);
            actoritr->second.SearchUniqueCoActor(ActorName);
        }
    }
    void showBlah(map<string,MovieList> &M, string name)
    {
        map<string, MovieList>::iterator itr;
        itr = M.find(name);
        itr->second.showMovies();

    }


    void checkblah(string actor, map<string,MovieList> &hashmaptemp)
    {
        map<string, MovieList> tempMap(actorListHashmap.begin(),actorListHashmap.end());
        map<string, MovieList>::iterator actoritrl;

        // cout << "\nThe map gquiz1 is : \n";
        // cout << "\tKEY\tELEMENT\n";
        // int count = 1;
        // for (actoritrl = tempMap.begin(); actoritrl != tempMap.end(); ++actoritrl)
        // {
        //        if(count > 50)
        //             break;
        //         count++;
        //     cout << '\t' << actoritrl->first << endl;
        //     actoritrl->second.showMovies();
        // }
        if (tempMap.count(actor) == 0)
            cout << "Actor Not Found Blah" << endl;
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = tempMap.find("Christoph Waltz");
            showBlah(hashmaptemp,actor);

            // actoritr->second.showMoviesAndRatings();
        }
    }

    //Parser
    ifstream myFileStream;       //initialize a file stream
    void SetFile(char *filename) //select file to parse
    {
        myFileStream.open(filename); //open selected file
        if (myFileStream.fail())     //Show error message if the file failed to open
            cout << "File does not exist" << endl;
        string line;
        int count = 1;
        int itPe = 0;

        int itP = 0;

        while (getline(myFileStream, line))
        {
            //parse each line separately
            stringstream ss(line);
            Movie m;
            string tempString;
            string tempString2;
            string tempString3;
            string x;
            //parse each string to right field
            getline(ss, tempString, '#');

            if (tempString[0] == '"')
            {
                tempString.erase(0, 1);
                getline(ss, x, ',');
            }
            else
            {
                getline(ss, x, ',');
            }
            m.setMovieTitle(tempString);
            getline(ss, tempString, ',');
            if (count < 5)
            {
                //cout << tempString << endl;
                count++;
            }
            stringstream tempss(tempString);
            LinkedList<string> genre;
            while (getline(tempss, tempString2, '|'))
            {
                genre.InsertAtEnd(tempString2);
            }
            m.setGenres(genre);
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setTitleYear(-1);
            }
            else
            {
                m.setTitleYear(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setImdbScore(-1.0);
            }
            else
            {
                m.setImdbScore(stod(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setDirectorName("-1");
            }
            else
            {
                m.setDirectorName(tempString);
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setDirectorFbLikes(-1);
            }
            else
            {
                m.setDirectorFbLikes(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setNumCriticForReviews(-1);
            }
            else
            {
                m.setNumCriticForReviews(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setDuration(-1);
            }
            else
            {
                m.setDuration(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setActor1Name("-1");
            }
            else
            {
                m.setActor1Name(tempString);
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setActor1FbLikes(-1);
            }
            else
            {
                m.setActor1FbLikes(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setActor2Name("-1");
            }
            else
            {
                m.setActor2Name(tempString);
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setActor2FbLikes(-1);
            }
            else
            {
                m.setActor2FbLikes(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setActor3Name("-1");
            }
            else
            {
                m.setActor3Name(tempString);
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setActor3FbLikes(-1);
            }
            else
            {
                m.setActor3FbLikes(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setGross(-1);
            }
            else
            {
                m.setGross(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setNumVotedUsers(-1);
            }
            else
            {
                m.setNumVotedUsers(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setCastTotalFacebookLikes(-1);
            }
            else
            {
                m.setCastTotalFacebookLikes(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setFacenumberInPoster(-1);
            }
            else
            {
                m.setFacenumberInPoster(stol(tempString));
            }
            getline(ss, tempString, ',');
            stringstream tempss2(tempString);
            LinkedList<string> PlotKeywords;
            while (getline(tempss, tempString2, '|'))
            {
                PlotKeywords.InsertAtEnd(tempString2);
            }
            m.setPlotKeywords(PlotKeywords);
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setMovieImdbLink("-1");
            }
            else
            {
                m.setMovieImdbLink(tempString);
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setNumUserForReviews(-1);
            }
            else
            {
                m.setNumUserForReviews(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setLanguage("-1");
            }
            else
            {
                m.setLanguage(tempString);
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setCountry("-1");
            }
            else
            {
                m.setCountry(tempString);
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setContentRating("-1");
            }
            else
            {
                m.setContentRating(tempString);
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setBudget(-1);
            }
            else
            {
                m.setBudget(stoll(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setAspectRatio(-1.0);
            }
            else
            {
                m.setAspectRatio(stof(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setMovieFbLikes(-1.0);
            }
            else
            {
                m.setMovieFbLikes(stol(tempString));
            }
            getline(ss, tempString, ',');
            if (tempString.empty())
            {
                m.setColor("-1");
            }
            else
            {
                m.setColor(tempString);
            }

            InsertMovie(m); //insert each movie parsed into movielist

            //hashmaps
            //hashmaps
            //hashmaps
            //hashmaps
            //hashmaps
            //hashmaps
            if (directorListHashmap.count(m.getDirectorName()) == 0)
            {
                MovieList tempmovie;
                // tempmovie.InsertMovie(m);
                // itPe++;
                // cout << itPe << endl;
                directorListHashmap.insert(pair<string, MovieList>(m.getDirectorName(), tempmovie));
            }

            map<string, MovieList>::iterator directoritr;
            directoritr = directorListHashmap.find(m.getDirectorName());
            directoritr->second.InsertMovie(m);
            // itPe++;
            // cout << itPe << endl;

            if (actorListHashmap.count(m.getActor1Name()) == 0)
            {
                MovieList tempactorlist1;
                actorListHashmap.insert(pair<string, MovieList>(m.getActor1Name(), tempactorlist1));
                // itP++;
                // cout << "\t\t " << itP << endl;
            }

            map<string, MovieList>::iterator actor1itr;
            actor1itr = actorListHashmap.find(m.getActor1Name());
            actor1itr->second.InsertMovie(m);
            // itP ++;
            // cout << "\t\t " << itP << endl;

            if (actorListHashmap.count(m.getActor2Name()) == 0)
            {
                MovieList tempactorlist2;
                actorListHashmap.insert(pair<string, MovieList>(m.getActor2Name(), tempactorlist2));
                // itP++;
                // cout << "\t " << itP << endl;
            }

            map<string, MovieList>::iterator actor2itr;
            actor2itr = actorListHashmap.find(m.getActor2Name());
            actor2itr->second.InsertMovie(m);
            // itP ++;
            // cout << "\t\t " << itP << endl;

            if (actorListHashmap.count(m.getActor3Name()) == 0)
            {
                MovieList tempactorlist3;
                actorListHashmap.insert(pair<string, MovieList>(m.getActor3Name(), tempactorlist3));
                // itP++;
                // cout << "\t\t " << itP << endl;
            }

            map<string, MovieList>::iterator actor3itr;
            actor3itr = actorListHashmap.find(m.getActor3Name());
            actor3itr->second.InsertMovie(m);

            if (movieYearHashmap.count(m.getTitleYear()) == 0)
            {
                MovieList tempMovieYear;
                tempMovieYear.InsertMovie(m);
                movieYearHashmap.insert(pair<int, MovieList>(m.getTitleYear(), tempMovieYear));
            }

            map<int, MovieList>::iterator movieYearitr;
            movieYearitr = movieYearHashmap.find(m.getTitleYear());
            movieYearitr->second.InsertMovie(m);

            if (movieNameHashmap.count(m.getMovieTitle()) == 0)
            {
                MovieList tempMovieYear;
                tempMovieYear.InsertMovie(m);
                movieNameHashmap.insert(pair<string, MovieList>(m.getMovieTitle(), tempMovieYear));
            }

            map<string, MovieList>::iterator movieNameitr;
            movieNameitr = movieNameHashmap.find(m.getMovieTitle());
            movieNameitr->second.InsertMovie(m);

            for (int i = 0; i < genre.length; i++)
            {
                // cout << "k" << endl;
                string tempGenre = genre.valueAtIndex(i);
                // cout << "j" << endl;
                if (genreHashmap.count(tempGenre) == 0)
                {
                    // cout << "h" << endl;
                    MovieList tempMovieGenre;
                    // cout << "g" << endl;
                    genreHashmap.insert(pair<string, MovieList>(tempGenre, tempMovieGenre));
                }
                // cout << "f" << endl;

                map<string, MovieList>::iterator movieGenreitr;
                // cout << "d" << endl;

                movieGenreitr = genreHashmap.find(tempGenre);
                // cout << "s" << endl;
                movieGenreitr->second.InsertMovie(m);
            }

            // itP ++;

            // cout << "\t\t\t " << itP << endl;

            // if(directorListHashmap.count(m.getDirectorName()) == 0)
            // {
            //     tempmovie.InsertMovie(m);
            //     itPe++;

            //     itPe++;

            //     cout << itPe << endl;
            // }
        }
    }
};

//main
int main()
{
    MovieList M = MovieList(MovieList());
    const char *p1 = "E:\\OneDrive - National University of Sciences & Technology\\1. Uni Semester\\3rd Semester\\Data Structures & Algorithms\\Labs\\IMDB-Search-Engine\\test.txt";
    char *p2;
    p2 = const_cast<char *>(p1);
    M.SetFile(p2);

    /* M.printDirector("Ben Stiller");
     string t;
     cout << "\nHint: Enter Johnny Depp\n\nEnter the name of the Actor:  ";
     getline(cin,t);
     cout << t << endl;
     M.printActorMovies(t);*/

    M.printActorCoactors("Jada Pinkett Smith");
    M.printCoactorsOfCoactors("CCH Pounder", M);
    string Actorname = "CCH Pounder";
    M.checkblah(Actorname,M.actorListHashmap);
    // M.checkIfCoActor("Christoph Waltz", "Rory Kinnear");
    cout << endl;
    //M.printUniqueCoActor("Jimmy Bennett");

    //M.printCheckIfCoActor("CCH Pounder", "Jimmy Bennett");
    // SearchActor("CCH Pounder", M);
    return 0;
}
