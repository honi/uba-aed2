% Informaci?n sobre la clase para el sistema
\NeedsTeXFormat{LaTeX2e}
\RequirePackage{rcs}

% Notar que la pr?ctica los redefine, pero para cuando eso sucede, ya
% no los necesitamos, as? que est? bien.
\RCSdef $Revision: 1.2 $
\RCSdate $Date: 2008/03/18 14:45:57 $

%\ProvidesClass{aed2-practica}[\RCSDate\space v\RCSRevision\space Para componer gu\'ias de ejs. para las pr\'acticas de AED2]
\LoadClass[a4paper]{article}

% Imprimir un mensajito al compilar un .tex que use esta clase
%\typeout{Cargando documentclass 'aed2-practica' v\RCSRevision, \RCSDate}



% ========== Carga de packages ==========

% babel para separaci?n en s?labas
\RequirePackage[spanish]{babel}

% inputenc para manejarnos con encoding Latin-1
%\RequirePackage[latin1]{inputenc}

% para componer TADs
\RequirePackage{aed2-tad}

% para s?mbolos de uso frecuente en Algo 2
\RequirePackage{aed2-symb}

% para poder referenciar el nro de la ?ltima p?gina
\RequirePackage{lastpage}

% para m?s opciones al enumerar / itemizar
\RequirePackage{enumerate}

% para calculitos inline
\RequirePackage{calc}

% para marcos bonitos y leftbars
\RequirePackage{framed}

% para pasarle opciones a la clase
\RequirePackage{xkeyval}

% para que bools e ifs sean m?s "amigables" que los de TeX
\RequirePackage{ifthen}

% para generar hiperv?nculos en el PDF de salida
\RequirePackage[colorlinks=true, linkcolor=blue, bookmarks=true, bookmarksopen=true]{hyperref}

% Definimos las dimensiones del documento via geometry
\RequirePackage{geometry}
\geometry{a4paper,margin=2.0cm,top=2.5cm,bottom=2.5cm}

% ========== Manejo de opciones ==========

% Creamos un flag para indicar "modo docente" (false por defecto)
\newboolean{mododocente}
\setboolean{mododocente}{false}
\newcommand{\elano}{2004}
\newcommand{\elcuat}{1^{\mathrm{er}}}

\newboolean{sinfecha}
\setboolean{sinfecha}{false}

% Sale para alumnos a menos que se use la opci?n [mododocente]
\DeclareOptionX{mododocente}{\setboolean{mododocente}{true}}
\DeclareOptionX{ano}{\renewcommand{\elano}{#1}}
\DeclareOptionX{cuat}{\ifthenelse{#1=2}
	{\renewcommand{\elcuat}{2^{\mathrm{do}}}}% Si es segundo, se cambia.
	{}% Si no, queda el valor predeterminado (primero).
}
\DeclareOptionX{sinfecha}{\setboolean{sinfecha}{true}}

\ProcessOptionsX

% ========== Decisiones de formato ==========

% Anulo la distancia extra entre ?temes.
\let\olditemize\itemize
\def\itemize{\olditemize\itemsep=-\parsep}

% Tratar de no dividir palabras.
\sloppy


% Package fancyhdr, y definimos headers/footers standard
% Esto *debe* estar despues de geometry!
\RequirePackage{fancyhdr}
\pagestyle{fancy}
\lhead{Algoritmos y Estructuras de Datos II}
\chead{}
{\rhead{{\ifthenelse{\boolean{sinfecha}}{}{$\elcuat$ cuatrimestre de \elano}}}}
\renewcommand{\headrulewidth}{0.5pt}
\lfoot{}
\cfoot{P\'agina \thepage\ de \pageref{LastPage}}
\rfoot{}
\renewcommand{\footrulewidth}{0.5pt}


% ========== Variables globales ==========

% Contadores para el nro de parte y el nro de ejercicio
\newcounter{parte}
\newcounter{ejercicio}

% Defininimos el nivel de anidamiento para los bookmarks del PDF
\def\toclevel@parte{0}
\def\toclevel@ejercicio{1}


% ========== Constantes configurables ==========

% S?mbolo para marcar los ejercicios importantes (estrellita)
\newcommand\importante{\raisebox{0.5pt}{\ensuremath{\bigstar}}}

% Strings constantes
\newcommand\strobjetivos{Objetivos pedag\'ogicos}
\newcommand\strjustificacion{Justificaci\'on de importancia}
\newcommand\strsolucion{Idea de la soluci\'on}



% ========== Macros y entornos ==========

% Para componer el encabezado standard de una gu?a
% Recibe el nro de pr?ctica y un t?tulo breve
\newcommand\titulopractica[2]{%
	% Acomodamos los par?metros del PDF
	\hypersetup{%
		pdfauthor={C\'atedra de Algoritmos y Estructuras de Datos II - DC - UBA},
		pdfkeywords={#2},
		pdftitle={Pr\'actica #1 - versi\'on \RCSRevision\ del \RCSDate},
		pdfsubject={Pr\'actica #1 - #2}
	}
	% Componemos el encabezado
	\begin{center}
	{\Large \textbf{Algoritmos y Estructuras de Datos II}}
	\par\vskip12pt
	{\large Pr\'actica #1 -- #2\solodocente{ -- Versi\'on para docentes}}
	\end{center}\vskip12pt
}

% Para componer las notas preliminares (van itemizadas)
\newenvironment{notasprelim}%
{%
	\begin{center}\begin{minipage}{0.9\textwidth}
	\titulo{\textbf{Notas preliminares}}
	\par \begin{itemize}
} {%
	\end{itemize}\end{minipage}
	\end{center}
	\vskip12pt
	\rule{\textwidth}{0.5pt}
	\vskip14pt
}

% Auxiliar para darle formato a un t?tulo (de ejercicio o nivel equivalente)
\newcommand\titulo[1]{%
	\noindent #1
}

% Auxiliar para componer algo sii mododocente == true
\newcommand\solodocente[1]{\ifthenelse{\boolean{mododocente}}{#1}{}}

% Auxiliar para darle formato a una secci?n "s?lo para docentes"
% Recibe el t?tulo y el contenido de la secci?n.
\newcommand\secciondocente[2]{%
	\solodocente{
		\par\hangindent=2em\hangafter=1\indent
		\begin{small}
		\titulo{\textsf{\textbf{#1}}}
		{\sf #2}
		\end{small}
	}
}

% Para componer un comentario (para docentes) dentro de un ejercicio
% Recibe opcionalmente el autor, y (obligatoriamente) el texto.
\newcommand\observacion[2][nadie]{\solodocente{\smallskip\begin{leftbar}\secciondocente{Observaci\'on\ifthenelse{\equal{#1}{nadie}}{}{ (por #1)}:}{#2}\end{leftbar}}}

% Para componer un pendiente (para docentes) dentro de un ejercicio
% Recibe opcionalmente el autor, y (obligatoriamente) el texto.
\newcommand\pendiente[2][nadie]{\solodocente{\smallskip\begin{leftbar}\secciondocente{Pendiente\ifthenelse{\equal{#1}{nadie}}{}{ (por #1)}:}{#2}\end{leftbar}}}

% Para indicar el comienzo de una Parte. Recibe el nombre de la Parte.
\newcommand\parte[1]{%
	\vspace{10pt} \noindent \textbf{\large Parte \addtocounter{parte}{1}\theparte\ -- #1}%
	% Agregamos la Parte a la TOC del PDF
	\phantomsection
	\addcontentsline{toc}{parte}{Parte \theparte\ - #1}%
}

% Para componer listas de incisos. Adentro se usa \item normalmente.
% Por ahora, un enumerate modificado y metido adentro de una minipage.
\newenvironment{incisos}%
{%
	\par\medskip
	\begin{minipage}{0.9\textwidth}
	\begin{enumerate}[a)]\itemsep=-\parsep
} {%
	\end{enumerate}\end{minipage}
	\par\medskip
}

% Para componer un ejercicio.
% Recibe una key/value list como par?metro opcional.
\newenvironment{ejercicio}[1][]{%
	% Leemos el diccionario (ver m?s abajo)
	\newboolean{ejimportante}
	\setboolean{ejimportante}{false}
	\setkeys{ej}{#1}

	% Manejamos la opcionalidad de la importancia / justificaci?n.
	\ifthenelse{\boolean{ejimportante}}
		{\newcommand\ejimportancia{~\importante}}
		{\newcommand\ejimportancia{}}

	% Damos formato al nombre del ejercicio, si existe.
	\ifthenelse{\isundefined\ejnombre}
		{\newcommand\ejnombredisplay{}}
		{\newcommand\ejnombredisplay{~\textsl{(\ejnombre)}}}

	% Componemos el t?tulo completo e incrementamos el contador
	\titulo{\textbf{Ejercicio \addtocounter{ejercicio}{1}\theejercicio}\ejnombredisplay\ejimportancia}
	\medskip\par

	% Lo agregamos al ?ndice del PDF.
	\phantomsection
	\addcontentsline{toc}{ejercicio}{Ejercicio \theejercicio}%
} {%
	\solodocente{\begin{leftbar}}

	% Si hay objetivos, los mostramos ante todo.
	\ifthenelse{\isundefined\ejobjetivos}
		{}
		{\secciondocente{\strobjetivos:}{\ejobjetivos}}

	% Ahora va la justificaci?n de importancia, si existe.
	\ifthenelse{\isundefined\ejjustif}
		{}
		{\secciondocente{\strjustificacion:}{\ejjustif}}

	% Por ?ltimo, la idea de la soluci?n (tambien condicional a que exista).
	\ifthenelse{\isundefined\ejsolucion}
		{}
		{\secciondocente{\strsolucion:}{\ejsolucion}}

	\solodocente{\end{leftbar}}

	% Y dejamos un poco de espacio post-ejercicio
	\bigskip\par
}

% --- Diccionario para las opciones del entorno 'ejercicio' ---

% Label para el ejercicio (un ID que ser? citable via \ref{})
\define@key{ej}{label}{\label{#1}}

% Objetivos pedag?gicos del ejercicio.
\define@key{ej}{objetivos}{\newcommand\ejobjetivos{#1}}

% Idea de la soluci?n.
\define@key{ej}{solucion}{\newcommand\ejsolucion{#1}}

% Justificaci?n de importancia (si no es vac?a, el ej. es importante).
\define@key{ej}{justificacion}{%
	\setboolean{ejimportante}{true}
	\newcommand\ejjustif{#1}
}

% Nombre para el ejercicio.
\define@key{ej}{nombre}{\newcommand\ejnombre{#1}}




% Para que el PDF se abra a p?gina completa (emp?ricamente, parece
% que debe estar abajo de todo).
\hypersetup{
 pdfstartview= {FitH \hypercalcbp{\paperheight-\topmargin-1in-\headheight}}
}
