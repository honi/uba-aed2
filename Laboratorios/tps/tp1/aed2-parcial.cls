% $Id: parcial.cls,v 1.1 2007-03-22 00:23:46 gsteren Exp $
\NeedsTeXFormat{LaTeX2e}
\RequirePackage{rcs}

% Notar que la pr�ctica los redefine, pero para cuando eso sucede, ya
% no los necesitamos, as� que est� bien.
\RCSdef $Revision: 1.2 $
\RCSdate $Date: 2010/09/27 14:45:57 $

\ProvidesClass{aed2-parcial}[\RCSDate\space v\RCSRevision\space Parciales de AED2]
\LoadClass[a4paper, 10pt]{article}

% Imprimir mensajito al procesar un .tex que use este package.
%
\typeout{Cargando class 'aed2-parcial'}

% Configuraciones varias.
\RequirePackage[spanish]{babel}
\RequirePackage{xkeyval}
\RequirePackage{ifthen}
%\RequirePackage[T1]{fontenc}
\RequirePackage[dvips]{graphicx}
\RequirePackage{indentfirst}
\RequirePackage{latexsym}
\RequirePackage{fancyhdr}
\RequirePackage{lastpage}
\RequirePackage{placeins}
\RequirePackage[a4paper, left=2.5cm, right=1.5cm, bottom=2.0cm, top=2.0cm]{geometry}
\RequirePackage{aed2-symb}

% Hago que la tipograf�a por defecto para typewriter sea Courier.
\renewcommand{\ttdefault}{pcr}
\newcommand{\titulo}[1]{\noindent \textbf{#1}}
\renewcommand{\thesection}{Ej.\ \arabic{section}}
\newcommand{\puntaje}[1]{{\small \textit{(#1 ptos.)}}}

\newcommand{\fecha}{Fecha a\'un no definida}
\newcommand{\lasaclaraciones}{}
\newboolean{hayaclaracion}
\setboolean{hayaclaracion}{false}
\def\date#1{\renewcommand{\fecha}{#1}}
\def\parcial#1{\newcommand{\nombreparcial}{#1}}
\def\aclaraciones#1{\setboolean{hayaclaracion}{true}\renewcommand{\lasaclaraciones}{#1}}

% Valores por omisi�n.
\newcommand{\elano}{Anio a\'un no definido}
\newcommand{\elcuat}{\ensuremath{1^{\mathrm{er}}}}

\DeclareOptionX{ano}{\renewcommand{\elano}{#1}}
\DeclareOptionX{cuat}{%
   \ifthenelse{\equal{#1}{2}}%
     {\renewcommand{\elcuat}{\ensuremath{2^{\mathrm{do}}}}}%
     {}%
}
\ProcessOptionsX

% Tratar de no dividir palabras.
\sloppy

% Anulo la distancia extra entre �temes.
\let\olditemize\itemize
\def\itemize{\olditemize\itemsep=-\parsep}
\let\oldenumerate\enumerate
\def\enumerate{\oldenumerate\itemsep=-\parsep}

\parskip=3pt %

% Acomodo fancyhdr.
\pagestyle{fancy}
\addtolength{\headheight}{1pt}
\thispagestyle{fancy}
\lhead{Algoritmos y Estructuras de Datos II - DC - UBA}
\rhead{$\elcuat$ cuatrimestre de \elano}
\cfoot{\thepage /\pageref{LastPage}}
\renewcommand{\footrulewidth}{0.4pt}

\renewcommand{\maketitle}{
\begin{Large}
\begin{center}
\textbf{Algoritmos y Estructuras de Datos II}\\
\textbf{\nombreparcial\qquad--\qquad\fecha}
\end{center}
\end{Large}

\ifthenelse{\boolean{hayaclaracion}}{
  \titulo{Aclaraciones}

  \begin{small}
    \begin{itemize}
      \lasaclaraciones
    \end{itemize}
  \end{small}
}{}
}
