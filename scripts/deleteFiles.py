'''
 # @ Author: Allen
 # @ Create Time: 2023-07-09 23:02:21
 # @ Modified time: 2023-07-09 23:07:19
 # @ Description: python program to delete .py files from all subfolders inside a root folder .
 '''

import os

def delete_py_files(root_folder):
    for foldername, subfolders, filenames in os.walk(root_folder):
        for filename in filenames:
            if filename.endswith(".py"):
                file_path = os.path.join(foldername, filename)
                os.remove(file_path)


root_folder = "PATH_TO_ROOT_FOLDER"
delete_py_files(root_folder)
