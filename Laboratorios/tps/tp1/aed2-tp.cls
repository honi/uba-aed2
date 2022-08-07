% $Id: tp.cls,v 1.1 2007-03-22 00:23:47 gsteren Exp $
\NeedsTeXFormat{LaTeX2e}
\RequirePackage{rcs}
\RequirePackage{aed2-symb}
\RequirePackage{url}

\RCSdate $Date: 2011/08/06 00:23:47 $
\RCS $Revision: 1.1 $

\ProvidesClass{aed2-tp}[\RCSDate\space v\RCSRevision\space Trabajos pr'acticos de AED2]
\LoadClass[a4paper, 10pt]{article}

% Imprimir mensajito al procesar un .tex que use este package.
%
\typeout{Cargando class 'aed2-tp' v\RCSRevision, \RCSDate}

% Configuraciones varias.
\RequirePackage[spanish]{babel}
\RequirePackage{xkeyval}
\RequirePackage{ifthen}
%\RequirePackage[latin1]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage{graphicx}
\RequirePackage{indentfirst}
\RequirePackage{latexsym}
\RequirePackage{fancyhdr}
\RequirePackage{lastpage}
\RequirePackage{placeins}
\RequirePackage[a4paper, left=2.5cm, right=1.5cm, bottom=2.0cm, top=2.0cm]{geometry}

% Hago que la tipograf?a por defecto para typewriter sea Courier.
\renewcommand{\ttdefault}{pcr}

\def\date#1{\newcommand{\fecha}{#1}}

% Valores por omisi?n.
\newcommand{\elano}{2022}
\newcommand{\elcuat}{1^{\mathrm{er}}}
\newcommand{\eltipotp}{Trabajo pr\'actico}
\newcommand{\elnrotp}{1}
\newcommand{\eldiaentrega}{}
\newcommand{\lafechaentrega}{no definida a?n}
\newcommand{\lahoraentrega}{no definida a?n}
\newcommand{\eltitulo}{no definido a?n}
\newcommand{\elnombredeltad}{no definido a?n}
\newcommand{\laurl}{url no definida}

\DeclareOptionX{ano}{\renewcommand{\elano}{#1}}
\DeclareOptionX{cuat}{\ifthenelse{#1=2}
	{\renewcommand{\elcuat}{2^{\mathrm{do}}}}% Si es segundo, se cambia.
	{}% Si no, queda el valor predeterminado (primero).
}
\DeclareOptionX{tipotp}{\ifthenelse{\equal{#1}{recu}}
	{\renewcommand{\eltipotp}{Recuperatorio del trabajo pr\'actico}}% Si es el recu se cambia.
	{}% Si no, queda el valor predeterminado (TP).
}
\DeclareOptionX{nrotp}{\renewcommand{\elnrotp}{#1}}
\DeclareOptionX{horaentrega}{\renewcommand{\lahoraentrega}{#1}}
\DeclareOptionX{diaentrega}{\renewcommand{\eldiaentrega}{#1}}
\DeclareOptionX{mesentrega}{\renewcommand{\lafechaentrega}{\eldiaentrega\ de #1 de \elano\ a las \lahoraentrega\ hs.}}
\DeclareOptionX{titulo}{\renewcommand{\eltitulo}{#1}}
\DeclareOptionX{nombredeltad}{\renewcommand{\elnombredeltad}{#1\xspace}}
\DeclareOptionX{laurl}{\renewcommand{\laurl}{#1}}
\ProcessOptionsX

% Tratar de no dividir palabras.
\sloppy

% Anulo la distancia extra entre ?temes.
\let\olditemize\itemize
\def\itemize{\olditemize\itemsep=-\parsep}
\let\oldenumerate\enumerate
\def\enumerate{\oldenumerate\itemsep=-\parsep}

\parskip=0.5ex % ex es la altura de una x

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
\eltipotp\ \elnrotp: \eltitulo \\
\textbf{\elnombredeltad}
\end{center}
\end{Large}

\section*{Normativa}

\noindent \textbf{L\'{\i}mite de entrega}: \lafechaentrega

\noindent \textbf{Normas de entrega}: Ver ``Informaci\'on sobre la cursada'' en el sitio Web de la materia.\\
\noindent \phantom{\textbf{Normas de entrega}:} ({\small \url{\laurl}})
}
