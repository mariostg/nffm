/*
 *   Copyright (C) 2012 by Mario St-Gelais
 * 
 *   This file is part of NFFM.
 *
 *   NFFM is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   NFFM is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with NFFM.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NFFM_H
#define NFFM_H

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <malloc.h>
#include <ncurses.h> //includes stdio.h and stdbool.h
#include <pwd.h>      //for current user directory
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h> //pid
#include <sys/wait.h> //waitpid
#include <time.h>  //for file info
#include <unistd.h>    //exec

#define AT_DIR -1
#define AT_FILE 1
#define CONF_FILE ".config/nffm/extension.conf"
#define FILEMAX 30          //The number of files listed
#define MAXBEGIN 20         //Max number of characters allowed to set file begin with option.
#define MAXDIGIT 3           //not more than 999
#define MAXDIRECTORY 80      //Max Length of directory name
#define MAXDIRLIST 3000
#define MAXFILELIST 3000
#define MAXMENUSIZE 3000     //Max number of menu items
#define MENUHT 30           //The height of menu + header
#define MENUMAX 30           //The number of directories listed
#define MENUW 45             //The width of menu
#define ROOT "/"
#define SHOW_HIDDEN 0
#define STRLEN 1024
#define WINFILEW 45          //The width of file window
#define WINTRANSITW 35       //The width of the temporary display area of selected files

enum nffm_colors{MAGENTA_BLACK=1, YELLOW_BLACK=2, GREEN_BLACK=3, RED_BLACK=4, NFFM_ORANGE=10};

typedef struct{
	int menuitem;         //index of directory or filelist
	int diritemold;       //index to retain menuitem when tabbing
	int fileitemold;      //index to retain menuitem when tabbing
    int winmarker;        //-1=AT_DIR, 1=AT_FILE
    int linemarker;       //Goes from 0 to linecount
    int linemarkerfile;
    int linemarkerdir;  
    int linemax;          //or FILEMAX 
    int linecount;        //from directories or files list length
    int arrowcounter;     //Switch from arrowcounterdir or arrowcounterfile. 0 to linemax
    int arrowcounterdir;  //The screen row of the highlighted directory
    int arrowcounterfile; //The screen row of the highlighted file
}cursor;

struct filemarker {   //Keep a list of selected file to be actionned
    char fullpath[MAXDIRECTORY];
    struct filemarker *next;
};

struct filemarker *filemarker = NULL;

enum direction {UP=-1, DOWN=1, SAME=0};//To specify whether the cursor moves up or down.


typedef struct{
    char dirname[STRLEN];
    int dir_count;
    int file_count;
    long dir_size;
}directories;

typedef struct
{
    char extension[20];
    char path[80];
    char executable[80];
    char arg[3];
    char execarg[30];
}appCommand;

typedef struct{
    bool show_hidden;
    char file_ext[20];
    char file_begin[MAXBEGIN+1];
}options;

WINDOW *winheader, *winfooter, *windirinfo, *winmenu, 
       *winscrollable, *currentwin, *winfileinfo, *wintransit;

FILE * file_open(const char *filename, const char *mode);
appCommand getCommand(const char *extension);
bool UnmarkFile(struct filemarker **filelist, const char *filepath);
bool begins_with(const char *string, const char *begins);
bool ends_with(const char *string, const char *ends);
bool findMarkedFile(struct filemarker *filelist, char *filepath);
bool isHiddenFile(char s[]);
char * getFileExtension(const char *filename);
char *GetUserDir(void);
char *delimLong(long nbr);
char *delimStr(char nbr[]);
char *dtg(time_t *tm);
char *getUserText(const char *question);
char *join(const char s1[], const char s2[]);
char *printCursor(cursor c);
char *printCursor(cursor c);
cursor setCursor(int direction, int selection, cursor c);
directories DoDirectoryList(char adir[], char *directory_list[], char *file_list[], options opt);
int ReadLine(char c, char aLine[]);
int addslash(char adir[]);
int createDir(const char *parentDir, const char *childDir);
int createFile(const char *filepath);
int deleteFile(const char *filepath, bool confirmDeleteMany);
int deleteMarkedFile(struct filemarker **filelist);
int displayList(struct filemarker *filelist);
int drawmenu(char *list[], char *item, WINDOW *w, int fromline);
int filterfile(const struct dirent *d);
int getNumber(WINDOW *w);
int renameSelectedFile(const char *currentPath, const char *oldName);
int split(char delim, char *stringtosplit);
int xdgFile(char *file);
options setFileFilter(options opt);
struct stat fileStat(char filepath[]);
void logger(const char *logger);
void markOneMoreFile(struct filemarker **filelist, char *filepath);
void message(char *msg);
void normalColor(WINDOW *w, cursor c, char *item);
void refreshDirInfo(directories dirs);
void refreshFileInfo(char currentDir[], char currentFile[]);

#endif /* NFFM_H */
