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

#ifndef CONFIG_H
#define CONFIG_H

/*
 * When reaching the bottom of a directory or file list, going down again bring
 * the cursor to the beginning of the list.  If at the top and moving up again
 * brings the cursor at the bottom of the list.
 *
 * Directories cannot be deleted if it contain other directories or files.
 *
 */

#define NEXT_DIR             'j'   /*Next dir or file down the list according to active pane*/
#define PREVIOUS_DIR         'k'   /*Dir or file up the list according active pane*/ 
#define VIEW_FILES           'l'   /*View files of current dir*/
#define PARENT_DIR           'h'   /*Move one dir up the hierararchy*/
#define GOTO_DIR_NUMBER      'n'   //n followed by the dir or file number
#define MOVE_PAGE_DOWN       'F'   //Got that...
#define MOVE_PAGE_UP         'U'   //Got that...
#define DELETE_FILE          'd'   //Delete the file currently selected or the current directory.
#define DELETE_MARKED_FILE   'D'   //Delete all the marked files.
#define MARK_FILE            'm'   //Select multiple file for further acion.
#define HIDDEN_FILE          '.'   //Show or hide hidden files and directories.
#define OPEN_FILE            'o'   //Open the selected file with preferred application
#define GOTO_HOME_DIR        'H'   //Got to home user directory.
#define GOTO_ROOT_DIR        '/'   //Goto / directory.
#define CREATE_FILE          'c'   //Create an empty file in current directory or create directory
#define RENAME_FILE          'r'   //rename the selected file
#define SELECTBEGINWITH      '^'   //Select the files that begin with expression
#define SELECTWITHEXTENSION  'f'   //Filer for files with given extension
#define FORMATTHOUSAND       true  //Display number with thousand separator
#define CONFIRMDELETEMANY    true //Ask for confirmation of every file when deleting many files.
#define USECOLOR             true //Whether or not you want color.
#define ARCHIVEANDCOMPRESS   'z'  //tar plus gzip selected files.
#endif /* CONFIG_H */
