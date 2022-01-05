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
        length = 0;
    }
    //Copy Constructor
    MovieList(MovieList const &list)
    {
        length = 0;
    }

    //hashmaps decleration
    map<string, MovieList> directorListHashmap;
    map<string, MovieList> actorListHashmap;
    map<string, MovieList> genreHashmap;
    map<string, MovieList> movieNameHashmap;
    map<char, MovieList> movieInitialNameHashmap;
    map<int, MovieList> movieYearHashmap;

    //length of each Movielist
    int length;

    //getter of length of movie list
    int getLength()
    {
        return length;
    }

    //getter of length of movie list
    int getLengthMovieNode()
    {
        int length2 = 0;
        MovieNode *temp = start;
        while (temp != NULL)
        {
            length2++;
            temp = temp->next;
        }
        return length2;
    }

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
        length++;
    }
    //Prints movies titles by the specfic genre
    void showMoviesByDirector()
    {
        cout << length << endl;
        if (start != NULL)
        {
            MovieNode *temp = start;
            while (temp != NULL)
            {
                cout << temp->data.getMovieTitle() << endl;
                ListNode<string> *Loc_ = temp->data.getGenres().Head;
                while (Loc_ != NULL)
                {
                    cout << Loc_->data << "|";
                    Loc_ = Loc_->next;
                }
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

    //----------------Task 1----------------------
    void printSearchActor(string Actorname)
    {
        if (actorListHashmap.count(Actorname) == 0)
            cout << "Actor Not Found" << endl;
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = actorListHashmap.find(Actorname);
            actoritr->second.searchMoviesAndYear(Actorname);
        }
    }

    void searchMoviesAndYear(string ActorName)
    {
        ListNode<MovieNode> *movies;

        if (start != NULL)
        {

            MovieNode *temp = start;
            cout << "\nActor Name : " << ActorName << endl;
            cout << "Count of movies acted in : " << getLengthMovieNode() << endl;

            while (temp != NULL)
            {
                cout << temp->data.getMovieTitle() << " | " << temp->data.getTitleYear() << endl;
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

    void printUniqueCoActor(string ActorName)
    {
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

    void SearchUniqueCoActor(string name)
    {

        if (start != NULL)
        {
            multimap<string, string> actormoviemap;
            MovieNode *temp = start;

            while (temp != NULL)
            {
                //cout << "Movie Name: " << temp->data.getMovieTitle() << endl;
                //if actor is actor1 print actor2 and actor3
                if (name.compare(temp->data.getActor1Name()) == 0)
                {
                    actormoviemap.insert(make_pair(temp->data.getActor2Name(), temp->data.getMovieTitle()));
                    actormoviemap.insert(make_pair(temp->data.getActor3Name(), temp->data.getMovieTitle()));
                }
                //if actor is actor2 print actor1 and actor3
                else if (name.compare(temp->data.getActor2Name()) == 0)
                {
                    actormoviemap.insert(make_pair(temp->data.getActor1Name(), temp->data.getMovieTitle()));
                    actormoviemap.insert(make_pair(temp->data.getActor3Name(), temp->data.getMovieTitle()));
                }
                //if actor is actor3 print actor1 and actor2
                else
                {
                    actormoviemap.insert(make_pair(temp->data.getActor1Name(), temp->data.getMovieTitle()));
                    actormoviemap.insert(make_pair(temp->data.getActor2Name(), temp->data.getMovieTitle()));
                }
                temp = temp->next;
            } //end while

            //iterating thorugh multimap and printing each key once with all values
            string current_key = "";
            for (auto itr = actormoviemap.begin(); itr != actormoviemap.end(); ++itr)
            {
                if (current_key == itr->first)
                {
                    continue;
                }
                else
                {
                    current_key = itr->first;
                }

                const auto result = actormoviemap.equal_range(itr->first);
                cout << itr->first << " | ";
                for (auto it = result.first; it != result.second; ++it)
                {
                    cout << it->second << ", ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }

    //-------------------------------Task 4-------------------------------
    void printCoactorsOfCoactors(string Actorname, MovieList &movieList)
    {
        //making a temp copy of hashmap to pass on the function
        // assigning the elements from gquiz1 to gquiz2

        if (actorListHashmap.count(Actorname) == 0)
            cout << "Actor Not Found!" << endl;
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = actorListHashmap.find(Actorname);
            actoritr->second.searchCoActorOfCoActors(Actorname, movieList);
        }
    }
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

                printActorCoactors(coactor1, movieList);

                cout << "\n------------------------------------------------------------------" << endl;
                cout << "\t\tCoactor-2: " << coactor2 << endl;
                cout << "------------------------------------------------------------------" << endl;
                cout << "Co-Actors of " << coactor2 << " :-\n"
                     << endl;
                printActorCoactors(coactor2, movieList);
                temp = temp->next;
            }
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }

    void printActorCoactors(string Actorname, MovieList &movieList)
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

    //---------------Task 5--------------------------------

    void checkIFCoActor(string name1, string name2)
    {
        if (actorListHashmap.count(name1) == 0)
            cout << "Actor Not Found" << endl;
        else
        {
            map<string, MovieList>::iterator actoritr;
            actoritr = actorListHashmap.find(name1);
            actoritr->second.checkIfCoActor(name1, name2);
        }
    }
    void checkIfCoActor(string name1, string name2)
    {
        if (start != NULL)
        {
            MovieNode *temp = start;
            bool found = false;
            while (temp != NULL)
            {
                if (temp->data.getActor1Name() == name2 || temp->data.getActor2Name() == name2 || temp->data.getActor3Name() == name2)
                {
                    cout << name1 << " and " << name2 << " are co-actors in movie \"" << temp->data.getMovieTitle() << "\"." << endl;
                    found = true;
                }
                temp = temp->next;
            }
            if (!found)
            {
                cout << name1 << " and " << name2 << " are not co-actors in any movie." << endl;
            }
        }
        else
        {
            cout << "The list is Empty!" << endl;
        }
    }

    //-------------------Task 6---------------------
    void printDirector(string dname)
    {
        if (directorListHashmap.count(dname) == 0)
            cout << "Director Not Found" << endl;
        else
        {
            map<string, MovieList>::iterator directoritr;
            directoritr = directorListHashmap.find(dname);
            directoritr->second.showMoviesByDirector();
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

    //-------------------------------Task 5-------------------------------

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

    //-------------Task7----------------------------------------
    //Print directors who have directed movies of a specific genre

    void printDirectorOfGenre(string genre)
    {
        if (genreHashmap.count(genre) == 0)
            cout << "Genre Not Found" << endl;
        else
        {
            map<string, MovieList>::iterator genreitr;
            genreitr = genreHashmap.find(genre);
            genreitr->second.showMoviesByDirector();
        }
    }

    bool SearchGenre(string genre, LinkedList<string> genreList)
    {
        ListNode<string> *Loc_ = genreList.Head;
        bool found = false;
        if (genreList.Head == NULL)
        {
            return found;
        }

        while (Loc_ != NULL)
        {
            if (Loc_->data.compare(genre) == 0)
            {
                found = true;
                return found;
            }
            Loc_ = Loc_->next;
        };
    }

    //------------------Task8-----------------------------------
    void SearchMovie(string title)
    {
        if (movieInitialNameHashmap.count(title[0]) == 0)
            cout << "Movie Not Found" << endl;
        else
        {
            map<char, MovieList>::iterator initialitr;
            initialitr = movieInitialNameHashmap.find(title[0]);
            initialitr->second.SearchMovieinList(title);
        }
    }

    void SearchMovieinList(string title)
    {
        //Searches and stores the data in Loc_ of the given movie
        // LinkedList<MovieNode> movies;
        MovieNode *temp = start;

        while (temp != NULL)
        {

            int count = 0;
            for (int i = 0; i <= title.length(); i++)
            {
                if (title[i] == temp->data.getMovieTitle()[i])
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (count == title.length())
            {
                cout << "m" << endl;
                cout << " MOVIE TITLE: " << temp->data.getMovieTitle() << endl;
                cout << " GENRE: ";
                ListNode<string> *Loc_ = temp->data.getGenres().Head;
                while (Loc_ != NULL)
                {
                    cout << Loc_->data << "|";
                    Loc_ = Loc_->next;
                }
                cout << "Release Year: " << temp->data.getTitleYear() << endl;
                cout << "IMDB Score: " << temp->data.getImdbScore() << endl;
                cout << "Director: " << temp->data.getDirectorName() << endl;
                cout << "Director FB Likes: " << temp->data.getDirectorFbLikes() << endl;
                cout << "Number of critical views: " << temp->data.getNumCriticForReviews() << endl;
                cout << "Movie Duration: " << temp->data.getDuration() << endl;
                cout << "Actor 1 Name: " << temp->data.getActor1Name() << endl;
                cout << "Actor 1 FB Likes: " << temp->data.getActor1FbLikes() << endl;
                cout << "Actor 2 Name: " << temp->data.getActor2Name() << endl;
                cout << "Actor 2 FB Likes: " << temp->data.getActor2FbLikes() << endl;
                cout << "Actor 3 Name: " << temp->data.getActor3Name() << endl;
                cout << "Actor 3 FB Likes: " << temp->data.getActor3FbLikes() << endl;
                cout << "Gross: " << temp->data.getGross() << endl;
                cout << "Number of Voted Users: " << temp->data.getNumVotedUsers() << endl;
                cout << "Total FB Likes: " << temp->data.getCastTotalFacebookLikes() << endl;
                cout << "Face No. in Poster: " << temp->data.getFacenumberInPoster() << endl;
                cout << "Movie IMDB Link: " << temp->data.getMovieImdbLink() << endl;
                cout << "User for Reviews: " << temp->data.getNumUserForReviews() << endl;
                cout << "Movie Language: " << temp->data.getLanguage() << endl;
                cout << "Country: " << temp->data.getCountry() << endl;
                cout << "Content Rating: " << temp->data.getContentRating() << endl;
                cout << "Budget: " << temp->data.getBudget() << endl;
                cout << "Aspect Ratio: " << temp->data.getAspectRatio() << endl;
                cout << "Movie FB Likes: " << temp->data.getMovieFbLikes() << endl;
                cout << "Color: " << temp->data.getColor() << endl;
            }
            temp = temp->next;
        }
    }
    //------------Task9-----------------------------------
    //Prints all movies in a given year
    void SearchMovieInYear(int year)
    {
        if (movieYearHashmap.count(year) == 0)
            cout << "Movie Year Not Exists." << endl;
        else
        {
            map<int, MovieList>::iterator initialitr;
            initialitr = movieYearHashmap.find(year);
            initialitr->second.PrintMovieInYear(year);
        }
    }

    void PrintMovieInYear(int year)
    {
        LinkedList<string> MovieTitles;
        MovieNode *temp = start;
        while (temp != NULL)
        {
            if (temp->data.getTitleYear() == year)
            {
                MovieTitles.InsertAtEnd(temp->data.getMovieTitle());
            }
            temp = temp->next;
        }
        MovieTitles.PrintList();
    }

    //--------------Task10---------------
    //Prints the movies in ascending order

    void PrintMoviesYearWise(string order)
    {

        if (order == "ascend")
        {
            cout << "Printing in the Ascending Order\n"
                 << endl;
            map<int, MovieList>::iterator itr;
            for (itr = movieYearHashmap.begin(); itr != movieYearHashmap.end(); itr++)
            {
                cout << '\nMovie Year is :' << itr->first << endl;
                cout << endl;
                itr->second.PrintMoviesYearWiseF();
            }
        }
        else if (order == "descend")
        {
            cout << "Printing in the Descending Order\n"
                 << endl;
            map<int, MovieList>::reverse_iterator rev_itr;
            for (rev_itr = movieYearHashmap.rbegin(); rev_itr != movieYearHashmap.rend(); rev_itr++)
            {
                cout << '\nMovie Year is :' << rev_itr->first << endl;
                cout << endl;
                rev_itr->second.PrintMoviesYearWiseF();
            }
        }
    }

    void PrintMoviesYearWiseF()
    {
        string name;
        int year;
        LinkedList<MovieNode> movies;
        MovieNode *temp = start;
        while (temp != NULL)
        {
            movies.InsertAtEnd(*temp);
            temp = temp->next;
        }
        bubbleSortYear(&movies.Head, movies.getLength());
        ListNode<MovieNode> *temp2 = movies.Head;
        while (temp2 != NULL)
        {
            name = temp2->data.data.getMovieTitle();
            year = temp2->data.data.getTitleYear();
            if (year == -1)
            {
                cout << name << " | "
                     << "NULL Field" << endl;
            }
            else
            {
                cout << name << " | " << year << endl;
            }
            temp2 = temp2->next;
        }
    }
    //-------------Task11----------------------------------------
    //Search and print movies of a certain genre
    void SearchMovieByGenre(string genre)
    {
        if (genreHashmap.count(genre) == 0)
            cout << "Genre Not Found" << endl;
        else
        {
            map<string, MovieList>::iterator genreitr;
            genreitr = genreHashmap.find(genre);
            genreitr->second.PrintAllGenreMovie(genre);
        }
    }
    void PrintAllGenreMovie(string genre)
    {
        MovieNode *temp = start;
        LinkedList<string> GenreMovies;
        while (temp != NULL)
        {
            if (SearchGenre(genre, temp->data.getGenres()))
            {
                GenreMovies.InsertAtEnd(temp->data.getMovieTitle());
            }
            temp = temp->next;
        }
        GenreMovies.PrintList();
    }
    //------End of Task11-----------------------------------------

    //--------------Task12---------------

    //Prints the movies rating wise
    void PrintMoviesRatingWise()
    {
        string name;
        float rating;
        LinkedList<MovieNode> movies;
        MovieNode *temp = start;
        while (temp != NULL)
        {
            movies.InsertAtEnd(*temp);
            temp = temp->next;
        }
        bubbleSortRating(&movies.Head, movies.getLength());
        ListNode<MovieNode> *temp2 = movies.Head;
        while (temp2 != NULL)
        {
            name = temp2->data.data.getMovieTitle();
            rating = temp2->data.data.getImdbScore();
            if (rating == -1.0)
            {
                cout << name << " | "
                     << "NULL Field" << endl;
            }
            else
            {
                cout << name << " | " << rating << endl;
            }
            temp2 = temp2->next;
        }
    }

    //-------------Task13----------------------------------------
    //Search and print movies of a certain genre rating wise

    void PrintGenreRatingWise(string genre)
    {
        if (genreHashmap.count(genre) == 0)
            cout << "Genre Not Found" << endl;
        else
        {
            map<string, MovieList>::iterator genreitr;
            genreitr = genreHashmap.find(genre);
            genreitr->second.PrintGenreRatingWiseF(genre);
        }
    }
    void PrintGenreRatingWiseF(string genre)
    {
        string name;
        float rating;
        MovieNode *temp = start;
        LinkedList<MovieNode> GenreMovies;
        while (temp != NULL)
        {
            if (SearchGenre(genre, temp->data.getGenres()))
            {
                GenreMovies.InsertAtEnd(*temp);
            }
            temp = temp->next;
        }
        bubbleSortRating(&GenreMovies.Head, GenreMovies.getLength());
        ListNode<MovieNode> *temp2 = GenreMovies.Head;
        while (temp2 != NULL)
        {
            name = temp2->data.data.getMovieTitle();
            rating = temp2->data.data.getImdbScore();
            if (rating == -1.0)
            {
                cout << name << " | " << genre << "NULL Field" << endl;
            }
            else
            {
                cout << name << " | " << genre << " | " << rating << endl;
            }
            temp2 = temp2->next;
        }
    }
    //------End of Task13-----------------------------------------

    //-----------Functions to sort movies by year---------------
    //---------Big-O-Complexity O(n^2) n squared
    /*Function to swap the nodes */
    ListNode<MovieNode> *swap(ListNode<MovieNode> *ptr1, ListNode<MovieNode> *ptr2)
    {
        ListNode<MovieNode> *tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = tmp;
        return ptr2;
    }
    /* Function to sort the list by year */
    void bubbleSortYear(ListNode<MovieNode> **head, int count)
    {
        ListNode<MovieNode> **h;
        int i, j, swapped;

        for (i = 0; i <= count; i++)
        {

            h = head;
            swapped = 0;

            for (j = 0; j < count - i - 1; j++)
            {

                ListNode<MovieNode> *p1 = *h;
                ListNode<MovieNode> *p2 = p1->next;

                if (p1->data.data.getTitleYear() > p2->data.data.getTitleYear())
                {

                    /* update the link after swapping */
                    *h = swap(p1, p2);
                    swapped = 1;
                }

                h = &(*h)->next;
            }

            /* break if the loop ended without any swap */
            if (swapped == 0)
                break;
        }
    }
    //-----------End of Functions to sort movies by year---------------

    /* Function to sort the list by rating */
    void bubbleSortRating(ListNode<MovieNode> **head, int count)
    {
        ListNode<MovieNode> **h;
        int i, j, swapped;

        for (i = 0; i <= count; i++)
        {

            h = head;
            swapped = 0;

            for (j = 0; j < count - i - 1; j++)
            {

                ListNode<MovieNode> *p1 = *h;
                ListNode<MovieNode> *p2 = p1->next;

                if (p1->data.data.getImdbScore() < p2->data.data.getImdbScore())
                {

                    /* update the link after swapping */
                    *h = swap(p1, p2);
                    swapped = 1;
                }

                h = &(*h)->next;
            }

            /* break if the loop ended without any swap */
            if (swapped == 0)
                break;
        }
    }
    //-----------End of Functions to sort movies by rating---------------

    

    //Parser
    ifstream myFileStream;       //initialize a file stream
    void SetFile(char *filename) //select file to parse
    {
        myFileStream.open(filename); //open selected file
        if (myFileStream.fail())     //Show error message if the file failed to open
            cout << "File does not exist" << endl;
        string line;
        
        //file parser
        while (getline(myFileStream, line))
        {
            //parse each line separately
            stringstream ss(line);

            //objects to store and get data from streams
            Movie m;
            string tempString;
            string tempString2;
            string tempString3;
            string x;
            //parse each string to right field
            getline(ss, tempString, '#');

            /*parsing the file by line by line and then setting the data in the 
            movie object
            then passing that object in the insert function to insert it in the movieList class 
            as the movienode object i.e. as pointer
            and then storing those pointers in the hashmaps as MovieLists in them*/

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

            //insert each movie parsed into movielist
            InsertMovie(m);

            // data insertion in hashmaps

            //Data insertion in the Director Hash Map with director name as key and MovieList in the value which is made up of movienode class

            //checking if they key is alredy present or not
            if (directorListHashmap.count(m.getDirectorName()) == 0)
            {
                MovieList tempmovie;

                //if key is not present make a new <key, value> pair with key as that value
                directorListHashmap.insert(pair<string, MovieList>(m.getDirectorName(), tempmovie));
            }

            // making an iterator to iterate the map
            map<string, MovieList>::iterator directoritr;

            // getting the <Key,Value> pair in the iterator of the given key
            directoritr = directorListHashmap.find(m.getDirectorName());

            //inserting the data into the value with the key of the given director name
            directoritr->second.InsertMovie(m);

            //Data insertion in the Actor Hash Map with actor name as key and MovieList in the value which is made up of movienode class

            // for all the 3 movie actor insertions below

            //checking if they key is alredy present or not
            if (actorListHashmap.count(m.getActor1Name()) == 0)
            {
                MovieList tempactorlist1;

                //if key is not present make a new <key, value> pair with key as that value
                actorListHashmap.insert(pair<string, MovieList>(m.getActor1Name(), tempactorlist1));
            }

            // making an iterator to iterate the map
            map<string, MovieList>::iterator actor1itr;

            // getting the <Key,Value> pair in the iterator of the given key
            actor1itr = actorListHashmap.find(m.getActor1Name());

            //inserting the data into the value with the key of the given Actor name
            actor1itr->second.InsertMovie(m);

            //checking if they key is alredy present or not
            if (actorListHashmap.count(m.getActor2Name()) == 0)
            {
                MovieList tempactorlist2;

                //if key is not present make a new <key, value> pair with key as that value
                actorListHashmap.insert(pair<string, MovieList>(m.getActor2Name(), tempactorlist2));
            }

            // making an iterator to iterate the map
            map<string, MovieList>::iterator actor2itr;

            // getting the <Key,Value> pair in the iterator of the given key
            actor2itr = actorListHashmap.find(m.getActor2Name());

            //inserting the data into the value with the key of the given Actor name
            actor2itr->second.InsertMovie(m);

            //checking if they key is already present or not
            if (actorListHashmap.count(m.getActor3Name()) == 0)
            {
                MovieList tempactorlist3;

                //if key is not present make a new <key, value> pair with key as that value
                actorListHashmap.insert(pair<string, MovieList>(m.getActor3Name(), tempactorlist3));
            }

            // making an iterator to iterate the map
            map<string, MovieList>::iterator actor3itr;

            // getting the <Key,Value> pair in the iterator of the given key
            actor3itr = actorListHashmap.find(m.getActor3Name());

            //inserting the data into the value with the key of the given Actor name
            actor3itr->second.InsertMovie(m);

            // MovieYearHashMap with key as int i.e. release year of the movie

            //checking if they key is already present or not
            if (movieYearHashmap.count(m.getTitleYear()) == 0)
            {
                MovieList tempMovieYear;
                //if key is not present make a new <key, value> pair with key as that value
                movieYearHashmap.insert(pair<int, MovieList>(m.getTitleYear(), tempMovieYear));
            }

            // making an iterator to iterate the map
            map<int, MovieList>::iterator movieYearitr;

            // getting the <Key,Value> pair in the iterator of the given key
            movieYearitr = movieYearHashmap.find(m.getTitleYear());

            //inserting the data into the value with the key of the given Movie Release Year
            movieYearitr->second.InsertMovie(m);

            // MovieNameHashMap with movie name as the key and movieList as Value consisting of MovieNode class

            //checking if they key is already present or not
            if (movieNameHashmap.count(m.getMovieTitle()) == 0)
            {
                MovieList tempMovieYear;
                //if key is not present make a new <key, value> pair with key as that value
                movieNameHashmap.insert(pair<string, MovieList>(m.getMovieTitle(), tempMovieYear));
            }

            // making an iterator to iterate the map
            map<string, MovieList>::iterator movieNameitr;

            // getting the <Key,Value> pair in the iterator of the given key
            movieNameitr = movieNameHashmap.find(m.getMovieTitle());

            //inserting the data into the value with the key of the given Movie name
            movieNameitr->second.InsertMovie(m);

            //MovieNameInitialHashMap to store the movienode in the movielist as values
            // with the key as the initial of each movie

            //checking if they key is already present or not
            if (movieInitialNameHashmap.count(m.getMovieTitle()[0]) == 0)
            {
                MovieList tempMovieInitial;
                //if key is not present make a new <key, value> pair with key as that value
                movieInitialNameHashmap.insert(pair<char, MovieList>(m.getMovieTitle()[0], tempMovieInitial));
            }

            // making an iterator to iterate the map
            map<char, MovieList>::iterator movieNameInititr;

            // getting the <Key,Value> pair in the iterator of the given key
            movieNameInititr = movieInitialNameHashmap.find(m.getMovieTitle()[0]);

            //inserting the data into the value with the key of the Initial of the given Movie name
            movieNameInititr->second.InsertMovie(m);

            //running the loop equal to the no. of genre it has
            for (int i = 0; i < genre.length; i++)
            {
                //getting the genre at the index i in the linked list of genre
                string tempGenre = genre.valueAtIndex(i);

                //checking if they key is already present or not
                if (genreHashmap.count(tempGenre) == 0)
                {
                    MovieList tempMovieGenre;
                    //if key is not present make a new <key, value> pair with key as that value
                    genreHashmap.insert(pair<string, MovieList>(tempGenre, tempMovieGenre));
                }

                // making an iterator to iterate the map
                map<string, MovieList>::iterator movieGenreitr;

                // getting the <Key,Value> pair in the iterator of the given key
                movieGenreitr = genreHashmap.find(tempGenre);

                //inserting the data into the value with the key of the genre at index i of the given Movie name
                movieGenreitr->second.InsertMovie(m);
            }
        }
    }
};

void menu(MovieList &movieList)
{
    cout << "\n\t\t\tIMDB TERM PROJECT" << endl
         << endl;
    cout << "The following functions can be performed using the program: \n"
         << endl;
    cout << "ACTOR FUNCTIONS: \n";
    cout << "1. Search profile of an actor \n2. Search co-actors of an actor \n3. Search unique co-actors \n4. Print all co-actors of the co-actors of an actor \n5. Checks whether A and B are co-actors or not\n\n";
    cout << "DIRECTOR FUNCTIONS: \n";
    cout << "6. Search director \n7. Print directors who have directed movies of a certain genre \n\n";
    cout << "MOVIE FUNCTIONS: \n";
    cout << "8. Search a movie \n9. Search movies released in a given year \n10. Print movies year-wise \n11. Search movies based on genre \n12. Print movies rating-wise \n13. Print movies of a ertain genre rating-wise \n14. Exit Program\n\n";
    int option = 0, value, year;
    string name, genre, title;

    // DO-WHILE loop
    do
    {   
        //asking user which option he want to choose
        cout << "\nSelect an option: ";
        cin >> option;

        //running the option user choose
        if (option == 1)
        {
            cout << "Enter actor name: ";
            getline(cin, name);
            getline(cin, name);
            movieList.printSearchActor(name);
        }
        else if (option == 2)
        {
            cout << "Enter actor name whose co-actors are to be found: ";
            getline(cin, name);
            getline(cin, name);
            movieList.printActorCoactors(name);
        }
        else if (option == 3)
        {
            cout << "Enter actor name whose unique co-actors are to be found: ";
            getline(cin, name);
            getline(cin, name);
            movieList.printUniqueCoActor(name);
        }
        else if (option == 4)
        {
            cout << "Enter actor name: ";
            getline(cin, name);
            getline(cin, name);
            movieList.printCoactorsOfCoactors(name, movieList);
        }
        else if (option == 5)
        {
            string name1;
            string name2;
            cout << "Enter actor 1 name: ";
            getline(cin, name1);
            getline(cin, name1);
            cout << "Enter actor 2 name: ";
            getline(cin, name2);
            movieList.printCheckIfCoActor(name1, name2);
        }
        else if (option == 6)
        {
            cout << "Enter director name: ";
            getline(cin, name);
            getline(cin, name);
            movieList.printDirector(name);
        }
        else if (option == 7)
        {
            cout << "Enter genre: ";
            getline(cin, genre);
            getline(cin, genre);
            movieList.printDirectorOfGenre(genre);
        }
        else if (option == 8)
        {
            cout << "Enter movie title: ";
            getline(cin, title);
            getline(cin, title);
            movieList.SearchMovie(title);
        }
        else if (option == 9)
        {
            cout << "Enter release year: ";
            cin >> year;
            movieList.SearchMovieInYear(year);
        }
        else if (option == 10)
        {
            string choice;
            cout << "Press: \ni to print in increasing order\nd to print in decreasing order\nEnter choice: ";
            cin >> choice;
            if (choice == "i")
            {
                movieList.PrintMoviesYearWise("ascend");
            }
            else if (choice == "d")
            {
                movieList.PrintMoviesYearWise("descend");
            }
            else
            {
                cout << "Invalid Option!" << endl;
            }
        }
        else if (option == 11)
        {
            cout << "Enter genre: ";
            getline(cin, genre);
            getline(cin, genre);
            movieList.SearchMovieByGenre(genre);
        }
        else if (option == 12)
        {
            movieList.PrintMoviesRatingWise();
        }
        else if (option == 13)
        {
            string genre;
            cout << "Enter genre: ";
            getline(cin, genre);
            getline(cin, genre);
            movieList.PrintGenreRatingWise(genre);
        }
        else
        {
            cout << "Invalid option!\n";
        }
    } while (option != 14);

    cout << "Program ended.\n";
}
//main
int main()
{
    //Making a movieList object 
    MovieList M = MovieList(MovieList());

    //saving location of the dataset file
    const char *p1 = "E:\\OneDrive - National University of Sciences & Technology\\1. Uni Semester\\3rd Semester\\Data Structures & Algorithms\\Labs\\IMDB-Search-Engine\\test.txt";
    char *p2;
    p2 = const_cast<char *>(p1);

    //parsing the data file at the Given Location
    M.SetFile(p2);

    //calling the menu function and passing M in it to get it read the parsed data
    menu(M);

    return 0;
}
