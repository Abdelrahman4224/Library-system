#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Address{
    char
     Building[10]
    ,Street[10]
    ,City[10];
}Address;
typedef struct Date{
    int
     Year
    ,Month
    ,Day;
}Date;
typedef struct Book{
    char
     Title[20]
    ,Author[10]
    ,Publisher[10]
    ,Category[10];
    Date DateOfPublication;
    int AvailableCopies,NumberOfCopies,ISBN;
}Book;
typedef struct Member{
    char
     FirstName[10]
    ,LastName[10]
    ,PhoneNumber[12]
    ,EmailAddress[30];
    int ID,Age;
    Address Address;
}Member;
typedef struct Borrow{
    int UserID,ISBN;
    Date
     BorrowDate
    ,DueToReturn
    ,DateReturned;
}Borrow;
Borrow Borrows[100];
Book Books[100];
Member Members[100];
int BorrowsCount=0,BooksCount=0,MembersCount=0;

int readBooks(){
    FILE *f = fopen("books.txt", "r");
    if (f == NULL)
        return 0;
    while (!feof(f))
    {
        char line[100];
        fscanf(f, "%s",line);
        if(strlen(line)>0)
        {
            char *pt;
            pt = strtok (line,",");
            Books[BooksCount].ISBN=atoi(pt);
            pt = strtok (NULL, ",");
            if(pt)
                strcpy(Books[BooksCount].Author,pt);
            pt = strtok (NULL, ",");
            if(pt)
                strcpy(Books[BooksCount].Title,pt);
            pt = strtok (NULL, ",");
            if(pt)
                strcpy(Books[BooksCount].Publisher,pt);
            pt = strtok (NULL, ",");
            if(pt)
                strcpy(Books[BooksCount].Category,pt);
            pt = strtok (NULL, ",");
            Books[BooksCount].NumberOfCopies=atoi(pt);
            pt = strtok (NULL, ",");
            Books[BooksCount].AvailableCopies=atoi(pt);
            pt = strtok (NULL, ",");
            pt = strtok (pt, "-");
            Books[BooksCount].DateOfPublication.Day=atoi(pt);
            pt = strtok (NULL, "-");
            Books[BooksCount].DateOfPublication.Month=atoi(pt);
            pt = strtok (NULL, "-");
            Books[BooksCount].DateOfPublication.Year=atoi(pt);
            BooksCount++;
        }
    }
    fclose(f);
    return 1;
}
int writeBooks(){
    FILE *f = fopen("books.txt", "w");
    if (f == NULL)
        return 0;
    int i;
    for(i=0;i<BooksCount;i++)
    {
        fprintf(f, "%d,%s,%s,%s,%s,%d,%d,%d-%d-%d"
                ,Books[i].ISBN
                ,Books[i].Author
                ,Books[i].Title
                ,Books[i].Publisher
                ,Books[i].Category
                ,Books[i].NumberOfCopies
                ,Books[i].AvailableCopies
                ,Books[i].DateOfPublication.Day
                ,Books[i].DateOfPublication.Month
                ,Books[i].DateOfPublication.Year
                );
            if(i!=BooksCount-1)
            {
                fprintf(f,"\n");
            }
    }

    fclose(f);
    return 1;
}

int readBorrows(){
    FILE *f = fopen("borrows.txt", "r");
    if (f == NULL)
        return 0;
    while (!feof(f))
    {
        char line[100];
        fscanf(f, "%s",line);
        if(strlen(line)>0)
        {
            char *pt,*dueDate,*dateReturn,*borrowDate;
            pt = strtok (line,",");
            Borrows[BorrowsCount].UserID=atoi(pt);
            pt = strtok (NULL,",");
            Borrows[BorrowsCount].ISBN=atoi(pt);
            borrowDate = strtok (NULL, ",");
            dateReturn = strtok (NULL, ",");
            dueDate = strtok (NULL, ",");
            pt = strtok (borrowDate, "-");
            Borrows[BorrowsCount].BorrowDate.Day=atoi(pt);
            pt = strtok (NULL, "-");
            Borrows[BorrowsCount].BorrowDate.Month=atoi(pt);
            pt = strtok (NULL, "-");
            Borrows[BorrowsCount].BorrowDate.Year=atoi(pt);
            pt = strtok (dateReturn, "-");
            Borrows[BorrowsCount].DateReturned.Day=atoi(pt);
            pt = strtok (NULL, "-");
            Borrows[BorrowsCount].DateReturned.Month=atoi(pt);
            pt = strtok (NULL, "-");
            Borrows[BorrowsCount].DateReturned.Year=atoi(pt);
            pt = strtok (dueDate, "-");
            Borrows[BorrowsCount].DueToReturn.Day=atoi(pt);
            pt = strtok (NULL, "-");
            Borrows[BorrowsCount].DueToReturn.Month=atoi(pt);
            pt = strtok (NULL, "-");
            Borrows[BorrowsCount].DueToReturn.Year=atoi(pt);
            BorrowsCount++;
        }
    }
    fclose(f);
    return 1;
}
int writeBorrows(){
    FILE *f = fopen("borrows.txt", "w");
    if (f == NULL)
        return 0;
    int i;
    for(i=0;i<BorrowsCount;i++)
    {
        fprintf(f, "%d,%d,%d-%d-%d,%d-%d-%d,%d-%d-%d"
                ,Borrows[i].UserID
                ,Borrows[i].ISBN
                ,Borrows[i].BorrowDate.Day
                ,Borrows[i].BorrowDate.Month
                ,Borrows[i].BorrowDate.Year
                ,Borrows[i].DateReturned.Day
                ,Borrows[i].DateReturned.Month
                ,Borrows[i].DateReturned.Year
                ,Borrows[i].DueToReturn.Day
                ,Borrows[i].DueToReturn.Month
                ,Borrows[i].DueToReturn.Year
                );
            if(i!=BorrowsCount-1)
            {
                fprintf(f,"\n");
            }
    }
    fclose(f);
    return 1;
}
int readMembers(){
    FILE *f = fopen("Members.txt", "r");
    if (f == NULL)
        return 0;
    while (!feof(f))
    {
        char line[100];
        fscanf(f, "%s",line);
        if(strlen(line)>0)
        {
            char *pt;
            pt = strtok (line,",");
            Members[MembersCount].ID=atoi(pt);
            pt = strtok (NULL,",");
            Members[MembersCount].Age=atoi(pt);
            pt = strtok (NULL, ",");
            if(pt)
                strcpy(Members[MembersCount].FirstName,pt);
            pt = strtok (NULL,",");
            if(pt)
                strcpy(Members[MembersCount].LastName,pt);
            pt = strtok (NULL,",");
            if(pt)
                strcpy(Members[MembersCount].PhoneNumber,pt);
            pt = strtok (NULL,",");
            if(pt)
                strcpy(Members[MembersCount].EmailAddress,pt);
            pt = strtok (NULL,",");
            if(pt)
                strcpy(Members[MembersCount].Address.Building,pt);
            pt = strtok (NULL,",");
            if(pt)
                strcpy(Members[MembersCount].Address.Street,pt);
            pt = strtok (NULL,",");
            if(pt)
                strcpy(Members[MembersCount].Address.City,pt);
            MembersCount++;
        }
    }
    fclose(f);
    return 1;
}
int writeMembers(){
    FILE *f = fopen("Members.txt", "w");
    if (f == NULL)
        return 0;
    int i;
    for(i=0;i<MembersCount;i++)
    {
        fprintf(f, "%d,%d,%s,%s,%s,%s,%s,%s,%s"
                ,Members[i].ID
                ,Members[i].Age
                ,Members[i].FirstName
                ,Members[i].LastName
                ,Members[i].PhoneNumber
                ,Members[i].EmailAddress
                ,Members[i].Address.Building
                ,Members[i].Address.Street
                ,Members[i].Address.City
                );
        if(i!=MembersCount-1)
        {
            fprintf(f,"\n");
        }
    }
    fclose(f);
    return 1;
}
int readData(){
    int bookSuccess=readBooks();
    if(!bookSuccess)
        return -1; //  Code for books read Error
    int BorrowSuccess=readBorrows();
    if(!BorrowSuccess)
        return -2; //  Code for Borrow read Error
    int MemberSuccess=readMembers();
    if(!MemberSuccess)
        return -3; //  Code for Member read Error
    return 1;       // All data readed successfully
}
int saveData(){
    int bookSuccess=writeBooks();
    if(!bookSuccess)
        return -1; //  Code for books read Error
    int BorrowSuccess=writeBorrows();
    if(!BorrowSuccess)
        return -2; //  Code for Borrow read Error
    int MemberSuccess=writeMembers();
    if(!MemberSuccess)
        return -3; //  Code for Member read Error
    return 1;       // All data readed successfully
}
int searchMember(int id){
    int i;
    for(i=0;i<MembersCount;i++)
        if(Members[i].ID==id)
            return i;
    return -1;
}
void removeMember()
{
    int i;
    printf("Enter Id:");
    scanf("%d",&i);
    int memberIndex=searchMember(i);
    while(memberIndex==-1)
    {
        printf("ID Not Exist Enter ID:");
        scanf("%d",&i);
        memberIndex=searchMember(i);
    }
    for(i=memberIndex;i<MembersCount-1;i++)
    {
        Members[i]=Members[i+1];
    }
    MembersCount--;
}
void newMember(){
    char tmp[30];int i;
    Member m;
    printf("Enter Id:");
    scanf("%d",&i);
    while(searchMember(i)!=-1)
    {
        printf("ID Already Exist Enter ID:");
        scanf("%d",&i);
    }
    m.ID=i;
    printf("Enter Age:");
    scanf("%d",&i);
    m.Age=i;
    printf("Enter First Name:");
    scanf("%s",&tmp);
    strcpy(m.FirstName,tmp);
    printf("Enter Last Name:");
    scanf("%s",&tmp);
    strcpy(m.LastName,tmp);
    printf("Enter Phone Number:");
    scanf("%s",&tmp);
    strcpy(m.PhoneNumber,tmp);
    printf("Enter Email:");
    scanf("%s",&tmp);
    strcpy(m.EmailAddress,tmp);
    printf("Address Data:");
    printf("Enter Bulding:");
    scanf("%s",&tmp);
    strcpy(m.Address.Building,tmp);
    printf("Enter Street:");
    scanf("%s",&tmp);
    strcpy(m.Address.Street,tmp);
    printf("Enter City:");
    scanf("%s",&tmp);
    strcpy(m.Address.City,tmp);
    Members[MembersCount]=m;
    MembersCount++;
}
int searchBook(int ISBN){
    int i;
    for(i=0;i<BooksCount;i++)
        if(Books[i].ISBN==ISBN)
            return i;
    return -1;
}
void searchBookBy(char *type){
    char s[30];int i,flag=0;
    if(strcmp(type,"Author")==0)
    {
        printf("\nEnter Author Name:");
        scanf("%s",&s);
        for(i=0;i<BooksCount;i++)
            if(strcmp(Books[i].Author,s)==0)
            {
                 printf("\n%d,%s,%s,%s,%s,%d,%d,%d-%d-%d\n"
                ,Books[i].ISBN
                ,Books[i].Author
                ,Books[i].Title
                ,Books[i].Publisher
                ,Books[i].Category
                ,Books[i].NumberOfCopies
                ,Books[i].AvailableCopies
                ,Books[i].DateOfPublication.Day
                ,Books[i].DateOfPublication.Month
                ,Books[i].DateOfPublication.Year
                );
                flag=1;
            }
        if(!flag)
            printf("No Results Found");
    }
    else if(strcmp(type,"ISBN")==0)
    {
        printf("\nEnter ISBN:");
        scanf("%d",&i);
        for(i=0;i<BooksCount;i++)
            if(Books[i].ISBN==i)
            {
                 printf("\n%d,%s,%s,%s,%s,%d,%d,%d-%d-%d\n"
                ,Books[i].ISBN
                ,Books[i].Author
                ,Books[i].Title
                ,Books[i].Publisher
                ,Books[i].Category
                ,Books[i].NumberOfCopies
                ,Books[i].AvailableCopies
                ,Books[i].DateOfPublication.Day
                ,Books[i].DateOfPublication.Month
                ,Books[i].DateOfPublication.Year
                );
                flag=1;
            }
        if(!flag)
            printf("No Results Found");
    }
    else if(strcmp(type,"Title")==0)
    {
        printf("\nEnter Title:");
        scanf("%s",&s);
        for(i=0;i<BooksCount;i++)
            if(strcmp(Books[i].Title,s)==0)
            {
                 printf("\n%d,%s,%s,%s,%s,%d,%d,%d-%d-%d\n"
                ,Books[i].ISBN
                ,Books[i].Author
                ,Books[i].Title
                ,Books[i].Publisher
                ,Books[i].Category
                ,Books[i].NumberOfCopies
                ,Books[i].AvailableCopies
                ,Books[i].DateOfPublication.Day
                ,Books[i].DateOfPublication.Month
                ,Books[i].DateOfPublication.Year
                );
                flag=1;
            }
        if(!flag)
            printf("No Results Found");
    }
    if(strcmp(type,"Category")==0)
    {
        printf("\nEnter Category:");
        scanf("%s",&s);
        for(i=0;i<BooksCount;i++)
            if(strcmp(Books[i].Category,s)==0)
            {
                 printf("\n%d,%s,%s,%s,%s,%d,%d,%d-%d-%d\n"
                ,Books[i].ISBN
                ,Books[i].Author
                ,Books[i].Title
                ,Books[i].Publisher
                ,Books[i].Category
                ,Books[i].NumberOfCopies
                ,Books[i].AvailableCopies
                ,Books[i].DateOfPublication.Day
                ,Books[i].DateOfPublication.Month
                ,Books[i].DateOfPublication.Year
                );
                flag=1;
            }
        if(!flag)
            printf("No Results Found");
    }
}
void addNewCopies(){
    int i;
    printf("Enter ISBN:");
    scanf("%d",&i);
    int bookIndex=searchBook(i);
    while(bookIndex==-1)
    {
        printf("ISBN Not Exist Enter ISBN:");
        scanf("%d",&i);
        bookIndex=searchBook(i);
    }
    printf("Enter value:");
    scanf("%d",&i);
    Books[bookIndex].NumberOfCopies+=i;
    Books[bookIndex].AvailableCopies+=i;
}
void deleteBook(){
    int i;
    printf("Enter ISBN:");
    scanf("%d",&i);
    int bookIndex=searchBook(i);
    while(bookIndex==-1)
    {
        printf("ISBN Not Exist Enter ISBN:");
        scanf("%d",&i);
        bookIndex=searchBook(i);
    }
    for(i=bookIndex;i<BooksCount-1;i++)
    {
        Books[i]=Books[i+1];
    }
    BooksCount--;
}
void newBook(){
    char tmp[30];int i;
    Book b;
    printf("Enter ISBN:");
    scanf("%d",&i);
    int bookIndex=searchBook(i);
    while(bookIndex!=-1)
    {
        printf("ISBN Already Exist Enter ISBN or enter -1 to increament number of copies:");
        scanf("%d",&i);
        if(i==-1)
        {
            printf("Enter value:");
            scanf("%d",&i);
            Books[bookIndex].NumberOfCopies+=i;
            Books[bookIndex].AvailableCopies+=i;
            return;
        }
        else{
            bookIndex=searchBook(i);
        }
    }
    b.ISBN=i;
    printf("Enter Title:");
    scanf("%s",&tmp);
    strcpy(b.Title,tmp);
    printf("Enter Author:");
    scanf("%s",&tmp);
    strcpy(b.Author,tmp);
    printf("Enter Publisher:");
    scanf("%s",&tmp);
    strcpy(b.Publisher,tmp);
    printf("Enter Category:");
    scanf("%s",&tmp);
    strcpy(b.Category,tmp);
    printf("Publication Date Data:");
    printf("Enter day:");
    scanf("%d",&i);
    b.DateOfPublication.Day=i;
    printf("Enter Month:");
    scanf("%d",&i);
    b.DateOfPublication.Month=i;
    printf("Enter Year:");
    scanf("%d",&i);
    b.DateOfPublication.Year=i;
    printf("Enter Available Number of Copies:");
    scanf("%d",&i);
    b.AvailableCopies=i;
    b.NumberOfCopies=i;
    Books[BooksCount++]=b;
}
int searchBorrow(int ISBN,int Id){
    int i;
    for(i=0;i<BorrowsCount;i++)
        if(Borrows[i].UserID==Id&&Borrows[i].ISBN==ISBN)
            return i;
    return -1;
}
void Return(){
    int isbn,id;
    printf("Enter ISBN:");
    scanf("%d",&isbn);
    printf("Enter User ID:");
    scanf("%d",&id);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int borrowIndex=searchBorrow(isbn,id);
    if(borrowIndex==-1)
    {
        printf("this user not borrow this book:");
        return;
    }
    Borrows[borrowIndex].DateReturned.Year=tm.tm_year + 1900;
    Borrows[borrowIndex].DateReturned.Month= tm.tm_mon + 1;
    Borrows[borrowIndex].DateReturned.Day= tm.tm_mday;
}
void newBorrow(){
    char tmp[30];int i;
    Borrow b;
    printf("Enter ISBN:");
    scanf("%d",&i);
    b.ISBN=i;
    int bookIndex=searchBook(b.ISBN);
    if(bookIndex==-1)
    {
        printf("No Book Matches ISBN");
        return;
    }
    if(Books[bookIndex].AvailableCopies==0)
    {
        printf("No Available Copies");
        return;
    }
    printf("Enter UserId:");
    scanf("%d",&i);
    if(searchMember(i)==-1)
    {
        printf("No User Found");
        return;
    }
    Books[bookIndex].AvailableCopies--;
    b.UserID=i;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    b.BorrowDate.Year=tm.tm_year + 1900;
    b.BorrowDate.Month= tm.tm_mon + 1;
    b.BorrowDate.Day= tm.tm_mday;
    printf("Due Date To Return:");
    printf("\nEnter day:");
    scanf("%d",&i);
    b.DueToReturn.Day=i;
    printf("Enter Month:");
    scanf("%d",&i);
    b.DueToReturn.Month=i;
    printf("Enter Year:");
    scanf("%d",&i);
    b.DueToReturn.Year=i;
    b.DateReturned.Day=0;
    b.DateReturned.Month=0;
    b.DateReturned.Year=0;
    Borrows[BorrowsCount++]=b;
}
void overdue(){
    int i;
    for(i=0;i<BorrowsCount;i++)
    {
        time_t t = time(NULL);// get today date
        struct tm tm = *localtime(&t);// get today date
        if(Borrows[i].DueToReturn.Year<(tm.tm_year + 1900)&&Borrows[i].DateReturned.Day==0)
        {
            int bookIndex=searchBook(Borrows[i].ISBN);
            printf("%s,%s,%s\n",Books[bookIndex].Title,Members[searchMember(Borrows[i].UserID)].FirstName,Members[searchMember(Borrows[i].UserID)].PhoneNumber);
        }
        else if(Borrows[i].DueToReturn.Year==(tm.tm_year + 1900)&&Borrows[i].DateReturned.Day==0)
        {
            if(Borrows[i].DueToReturn.Month<(tm.tm_mon + 1)&&Borrows[i].DateReturned.Day==0)
            {
                int bookIndex=searchBook(Borrows[i].ISBN);
                printf("%s,%s,%s\n",Books[bookIndex].Title,Members[searchMember(Borrows[i].UserID)].FirstName,Members[searchMember(Borrows[i].UserID)].PhoneNumber);
            }
            else if(Borrows[i].DueToReturn.Month==(tm.tm_mon + 1)&&Borrows[i].DateReturned.Day==0)
            {
                if(Borrows[i].DueToReturn.Day<tm.tm_mday&&Borrows[i].DateReturned.Day==0)
                {
                    int bookIndex=searchBook(Borrows[i].ISBN);
                    printf("%s,%s,%s\n",Books[bookIndex].Title,Members[searchMember(Borrows[i].UserID)].FirstName,Members[searchMember(Borrows[i].UserID)].PhoneNumber);
                }
            }
        }
    }
}
void popular(){
    int i,j,counts[BooksCount];
    for(j=0;j<BooksCount;j++)
    {
        counts[j]=0;
    }
    for(j=0;j<BooksCount;j++)
    {
        for(i=0;i<BorrowsCount;i++)
        {
            if(Borrows[i].ISBN==Books[j].ISBN)
            {
                counts[j]++;
            }
        }
    }
    for(j=1;j<=5;j++)
    {
        int maxIndex=0;
        for(i=1;i<BooksCount;i++)
        {
            if(counts[i]>counts[maxIndex])
            {
                maxIndex=i;
            }
        }
        printf("%s,%d\n",Books[maxIndex].Title,Books[maxIndex].AvailableCopies);
        counts[maxIndex]=-1;
    }

}
int main()
{
    int s,saveFlag=0;
    s=readData();
    if(s==-1)
    {
        printf("Error while reading Books data");
        return 1;
    }
    else if(s==-2)
    {
        printf("Error while reading Borrows data");
        return 1;
    }
    else if(s==-3)
    {
        printf("Error while raeding Members books data");
        return 1;
    }
    while(1)
    {
        printf("\n-----------------------------------------------------------");
        printf("\nBook Management (1)\n");
        printf("\tInsert, search, add new copies, delete, edit\n");
        printf("Member Management (2)\n");
        printf("\tRegister, remove\n");
        printf("Borrow Management (3)\n");
        printf("\tBorrow, return\n");
        printf("Administrative actions (4)\n");
        printf("\tOverdue, popular\n");
        printf("Save changes (5)\n");
        printf("Exit (6)\n");
        printf("\tSave and exit, exit without saving\n");
        printf("-----------------------------------------------------------");
        printf("\nEnter Input:");
        scanf("%d",&s);
        if(s==1)
        {
            printf("\n\t*********************");
            printf("\n\tInsert (1)\n\tSearch (2)\n\tAdd new copies (3)\n\tDelete (4)\n\tMain Menu (5)");
            printf("\n\t*********************");
            printf("\n\tEnter Input:");
            scanf("%d",&s);
            switch(s)
            {
                case 1:newBook();
                    break;
                case 2:
                    printf("\n\t*********************");
                    printf("\n\tBy Title (1)\n\tBy ISBN (2)\n\tBy Author (3)\n\tBy Category (4)");
                    printf("\n\t*********************");
                    printf("Enter Input:");
                    scanf("%d",&s);
                    switch(s){
                        case 1:searchBookBy("Title");
                            break;
                        case 2:searchBookBy("ISBN");
                            break;
                        case 3:searchBookBy("Author");
                            break;
                        case 4:searchBookBy("Category");
                            break;
                    }
                    break;
                case 3:addNewCopies();
                    break;
                case 4:deleteBook();
                    break;
                case 5:
                    break;
            }
        }
        else if(s==2)
        {
            printf("\n\t*********************");
            printf("\n\tRegister (1)\n\tremove (2)\n");
            printf("\n\t*********************");
            printf("\n\tEnter Input:");
            scanf("%d",&s);
            switch(s)
            {
                case 1:newMember();
                    break;
                case 2:removeMember();
                    break;
            }
        }
        else if(s==3)
        {
            printf("\n\t*********************");
            printf("\n\tBorrow (1)\n\treturn (2)");
            printf("\n\t*********************");
            printf("\n\tEnter Input:");
            scanf("%d",&s);
            switch(s)
            {
                case 1:newBorrow();
                    break;
                case 2:Return();
                    break;
            }
        }
        else if(s==4)
        {
            printf("\n\t*********************");
            printf("\n\tOverdue (1)\n\tpopular (2)\n");
            printf("\n\t*********************");
            printf("\n\tEnter Input:");
            scanf("%d",&s);
            switch(s)
            {
                case 1:overdue();
                    break;
                case 2:popular();
                    break;
            }
        }
        else if(s==5)
        {
            s=saveData();
            if(s==-1)
            {
                printf("\nError while saving Books data");
                return 1;
            }
            else if(s==-2)
            {
                printf("\nError while saving Borrows data");
                return 1;
            }
            else if(s==-3)
            {
                printf("\nError while saving Members books data");
                return 1;
            }
            else{
                printf("\nSaved Successfully");
            }
        }
        else if(s==6)
        {
            printf("\n\t*********************");
            printf("\n\tSave and exit (1)\n\tExit without saving (2)\n");
            printf("\n\t*********************");
            printf("\n\tEnter Input:");
            scanf("%d",&s);
            switch(s)
            {
                case 1:saveFlag=1;
                    break;
                case 2:saveFlag=0;
                    break;
            }
            break;
        }
    }
    if(saveFlag)
    {
        s=saveData();
        if(s==-1)
        {
            printf("\nError while saving Books data");
            return 1;
        }
        else if(s==-2)
        {
            printf("\nError while saving Borrows data");
            return 1;
        }
        else if(s==-3)
        {
            printf("\nError while saving Members books data");
            return 1;
        }
        else{
            printf("\nSaved Successfully");
        }
    }

    return 0;
}
