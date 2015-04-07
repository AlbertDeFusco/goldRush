# goldRush
Practical example of op_list_append in Cilk Plus

Included here is a working program demonstrating Cilk parallel reduction for the op_list_append type.
The program will allocate the memory required and run the computation first in serial and then in parallel using
cilk_for. The results are compared for accuracy and parallel effiency is computed for the Cilk execution.

To compile the program a Cilk capable version of the Intel C compiler must be installed.

<br><br>
An educational presentation is also provdided that introduces the conecpts of Data Race and Reduction along
with implementations in Cilk Plus.
A basic understanding of parallel computing conecepts is expected. The presentation was prapred in LaTeX Beamer
and requires the following packages.

```latex
\documentclass[fleqn,xcolor=table,11pt,final]{beamer}
\usepackage{amsmath,amsfonts,amssymb,pxfonts,xspace}                                      
\usepackage{textpos}
\usepackage{colortbl}
\usepackage{verbatim}                                                                     
\usepackage{graphicx}
\usepackage{color}                                                                        
\usepackage{listings}                                                                     
\usepackage{tikz} 
```
