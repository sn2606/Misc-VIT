x = c(1,2,3,4,5,6,7,8,9,10)
y = c(1,4,9,16,25,36,49,64,81,100)
plot(x,y)
a = 3 + 5i
Re(a)
mod(a)
Mod(a)
x = -2
abs(x)
3 %% 2
3 % 2
plot(x,y,type = "l")
clc
clc()
x = c(1,2,3,4,5,6,7,8,9,10)
y = c(1,4,9,16,25,36,49,64,81,100)
plot(x,y)
plot(x,y,type = "l")
plot(x,y,type = "l",col = "red")
plot(x,y,type = "l",col = "red", main = "employee info")
plot(x,y,type = "l",col = "red", main = "employee info",xl$ = "emp",yl$ = "age")
plot(x,y,type = "l",col = "red", main = "employee info",xl$ "emp",yl$ "age")
plot(x,y,type = "l",col = "red", main = "employee info",xlab = "emp",ylab = "age")
x <- seq(-pi,pi,0.1)
plot(x,sin(x))
plot(x,sin(x),type = "l")
plot(x,sin(x),type = "l",main = "Sine function",ylab = "sin(x)")
plot(x,sin(x),type = "b",main = "Sine function",ylab = "sin(x)")
plot(x,sin(x),type = "h",main = "Sine function",ylab = "sin(x)")
A = c(3,9,6,10,14,15,19,22)
B = c(24,34,50,52,56,66,72,78)
plot(A,B,tupe = "b",col = "red",main = "Production of units by two firms A and B",xlab = "Units produced by A",ylab = "Units produced by B")
plot(A,B,type = "b",col = "red",main = "Production of units by two firms A and B",xlab = "Units produced by A",ylab = "Units produced by B")
y = pnorm(800,1000,200)
10000*y
z2 = pnorm(1200,1000,200)
10000*(z2 - y)
qnorm(0.1,1000,200)
dpois(0,lambda = 1.5)
1 - ppois(2,lambda = 1.5)
x = seq(50)
x
par(mfrow(2,2))
par(mfrow = c(2,2))
plot(x,dbinom(x,200,0.005),xlab = "X",ylab = "Probability",main = "Binominal distribution")
x = seq(10)
x = seq(10)
par(mfrow = c(2,2))
plot(x,dbinom(x,200,0.005),xlab = "X",ylab = "Probability",main = "Binominal distribution")
plot(x,dpois(x,0.1),xlab = "X",ylab = "Probability",main = "Poisson distribution")
plot(x,dnorm(x,0,1),xlab = "X",ylab = "Probability",main = "Normal distribution: SNV")
plot(x,dnorm(x,50,5),xlab = "X",ylab = "Probability",main = "Normal distribution")
pkgs <- c("ggplot2", "dplyr", "tidyr",
"mosaicData", "carData",
"VIM", "scales", "treemapify",
"gapminder", "ggmap", "choroplethr",
"choroplethrMaps", "CGPfunctions",
"ggcorrplot", "visreg",
"gcookbook", "forcats",
"survival", "survminer",
"ggalluvial", "ggridges",
"GGally", "superheat",
"waterfalls", "factoextra",
"networkD3", "ggthemes",
"hrbrthemes", "ggpol",
"ggbeeswarm")
install.packages
install.packages(pkgs)
cls
library("graphics")
library("datasets")
data("mtcars")
str("mtcars")
str(mtcars)
print(head(mtcars, 4))
hist(mtcars$mpg)
library("ggplot2")
library("ggplot")
ggplot(mtcars, aes(x = mpg)) + geom_histogram(binwidth = 5)
ggplot(mtcars, aes(x = mpg)) + geom_histogram()
ggplot(mtcars, aes(x = mpg)) + geom_histogram(binwidth = 10)
ggplot(mtcars, aes(x = mpg)) + geom_histogram(binwidth = 5)
par(mar = c(4, 4, .1, .1))
str(mtcars)
plot(mpg, hp, data = subset(mtcars, am == 1), xlim = c(50, 450), ylim = c(5, 40))
plot(mpg ~ hp, data = subset(mtcars, am == 1), xlim = c(50, 450), ylim = c(5, 40))
plot(mtcars$mpg, mtcars$hp, data = subset(mtcars, am == 1), xlim = c(50, 450), ylim = c(5, 40))
plot(mpg ~ hp, data = subset(mtcars, am == 1), xlim = c(50, 450), ylim = c(5, 40))
points(mpg ~ hp, col = "red", data = subset(mtcars, am == 0))
legend()
legend(350, 40, c("1", "0"), title = "am", col = c("black", "red"), pch = c(1,1))
ggplot(mtcars, aes(x = mpg, y = hp, factor(am))) + geom_point()
ggplot(mtcars, aes(x = mpg, y = hp, color = factor(am))) + geom_point()
geoms <- help.search("geom_", package = "ggplot2")
geoms
str(geoms)
geoms$matches[1:5, 1:2]
geoms$matches[1:10, 1:2]
library("datasets")
data("mtcars")
ggplot(mtcars, aes(x = mpg, y = hp)) + geom_point()
library("ggplot2")
ggplot(mtcars, aes(x = mpg, y = hp)) + geom_point()
ggplot(mtcars, aes(x = mpg, y = hp)) + geom_point(aes(y = log10(mpg)))
ggplot(mtcars, aes(x = mpg, y = hp)) + geom_point(aes(y = log10(hp)))
mtcars$pred.mpg <- predict(lm(mpg~hp, data = mtcars))
p1 <- ggplot(mtcars, aes(x = hp, y = mpg))
p1 + geom_point(aes(color = wt)) + geom_line(aes(y = pred.mpg))
p2 <- ggplot(mtcars, aes(x = hp, y = mpg))
p2 + geom_point(aes(color = wt)) + geom_smooth()
p2 + geom_point(aes(color = wt)) + geom_smooth() + geom_text(aes(label = rownames(mtcars)), size = 2)
rownames(mtcars)
p2 + geom_point(aes(color = wt)) + geom_smooth() + geom_text(aes(label = rownames(mtcars)), size = 1)
p2 + geom_point(aes(color = wt)) + geom_smooth() + geom_text(aes(label = rownames(mtcars)), size = 3)
x = 2
var = 2
ggplot(mtcars, aes(x = mpg, y = hp)) + geom_point(aes(size = 2), color = "red")
ggplot(mtcars, aes(x = mpg, y = hp)) + geom_point(aes(size = var), color = "red")
ggplot(mtcars, aes(x = mpg, y = hp)) + geom_point(size = 2, color = "red")
ggplot(mtcars, aes(x = hp, y = mpg)) + geom_point(aes(color = wt, shape = factor(am)))
ggplot(mtcars, aes(x = disp, y = hp)) + geom_point(color = blue)
ggplot(mtcars, aes(x = disp, y = hp)) + geom_point(color = "blue")
ggplot(mtcars, aes(x = disp, y = hp)) + geom_point(aes(color = mpg))
args(geoms$matches[:, 0])
args(geoms$matches)
args(geoms$matches[1:5])
geoms
str(geoms)
geoms$matches$Topic
args(geoms$matches$Topic)
args(geoms$matches$Topic.value)
args(geom_boxplot)
args(geom_bar)
# ?geom_bin
?stat_bin
?stat_boxplot
ggplot(mtcars, aes(x = disp)) + geom_bar()
ggplot(mtcars, aes(x = disp)) + geom_bar(stat = "bin", binwidth = 4)
ggplot(mtcars, aes(x = disp)) + geom_bar(stat = "bin")
aggregate(mtcars["mpg"], mtcars["gear"], fun = mean)
aggregate(mtcars["mpg"], mtcars["gear"], FUN = mean)
mtc.sum <- aggregate(mtcars["mpg"], mtcars["gear"], FUN = mean)
mtc.sum
ggplot(mtc.sum, aes(x = gear, y = mpg)) + geom_bar()
ggplot(mtc.sum, aes(x = gear, y = mpg)) + geom_bar(stat = "bin")
ggplot(mtc.sum, aes(x = gear, y = mpg)) + geom_bar(stat = "identity")
ggplot(mtcars, aes(x = mpg, y = gear)) + geom_boxplot()
ggplot(mtcars, aes(x = gear, y = mpg)) + geom_boxplot()
ggplot(mtcars, aes(x = gear, y = mpg)) + geom_boxplot(aes(group = gear))
ggplot(mtcars, aes(x = mpg, y = gear)) + geom_boxplot(aes(group = gear))
ggplot(mtcars, aes(x = mpg, y = gear)) + geom_boxplot(aes(group = gear)) + geom_point()
ggplot(mtcars, aes(x = mpg, y = gear)) + geom_boxplot(aes(group = gear)) + geom_point(aes(color = gear))
ggplot(mtcars, aes(x = mpg, y = gear)) + geom_boxplot(aes(group = gear)) + geom_point(aes(color = factor(gear)))
ggplot(mtcars, aes(x = mpg, y = gear)) + geom_boxplot(aes(group = gear, color = factor(gear))) + geom_point(aes(color = factor(gear)))
str(mtcars)
mtcars$pred.hp = predict(lm(wt~hp, data = mtcars))
p1 <- ggplot(mtcars, aes(x = wt, y = hp)) + geom_point()
p1 + geom_line(aes(y = pred.hp))
mtcars$pred.hp <- predict(lm(wt~hp, data = mtcars))
p1 + geom_line(aes(y = pred.hp))
mtcars$pred.hp
mtcars$pred.hp <- predict(lm(hp~wt, data = mtcars))
p1 <- ggplot(mtcars, aes(x = wt, y = hp)) + geom_point()
p1 + geom_line(aes(y = pred.hp))
p6 <- ggplot(mtcars, aes(x = factor(gear), y = mpg))
p6 + geom_point(aes(color = wt))
p7 <- p6 + geom_point(aes(color = wt))
p8 <- p7 + scale_x_discrete("Number of gears", breaks = c("3", "4", "5"), labels = c("Three", "Four", "Five"))
p8
p9 <- p8 + scale_color_continuous("Weight", break = with(mtcars, c(min(wt), median(wt), max(wt))), labels = c("Light", "Medium", "Heavy"))
p9 <- p8 + scale_color_continuous("Weight", break = with(mtcars, c(min(wt), median(wt), max(wt))), labels = c("Light", "Medium", "Heavy"))
p9 <- p8 + scale_color_continuous("Weight", breaks = with(mtcars, c(min(wt), median(wt), max(wt))), labels = c("Light", "Medium", "Heavy"))
p9
p9 + scale_y_continuous("Miles per gallon")
p9 <- p8 + scale_color_continuous("Weight", breaks = with(mtcars, c(min(wt), median(wt), max(wt))), labels = c("Light", "Medium", "Heavy"), low = "gray80", high = "black")
p9 + scale_y_continuous("Miles per gallon")
p8 + scale_color_gradient2("Weight", breaks = with(mtcars, c(min(wt), median(wt), max(wt))), labels = c("Light", "Medium", "Heavy"), low = "blue", high = "red", mid = "gray80", midpoint = median(mtcars$wt))
p8 + scale_color_gradient2("Weight", breaks = with(mtcars, c(min(wt), median(wt), max(wt))), labels = c("Light", "Medium", "Heavy"), low = "blue", high = "red", mid = "gray", midpoint = median(mtcars$wt))
p8 + scale_color_gradient2("Weight", breaks = with(mtcars, c(min(wt), median(wt), max(wt))), labels = c("Light", "Medium", "Heavy"), low = "blue", high = "red", mid = "gray10", midpoint = median(mtcars$wt))
p8 + scale_color_gradient2("Weight", breaks = with(mtcars, c(min(wt), median(wt), max(wt))), labels = c("Light", "Medium", "Heavy"), low = "blue", high = "red", mid = "gray20", midpoint = median(mtcars$wt))
p8 <- ggplot(mtcars, aes(x = factor(gear)))
p8 <- ggplot(mtcars, aes(x = factor(gear), y = mpg))
p8 + geom_point(aes(size = wt)) + scale_size_continuous("Weight")
p8 + geom_point(aes(size = wt)) + scale_size_continuous("Weight", range = c(2, 10))
?scale_shape_discrete
df_shapes <- data.frame(shape = 0:24)
ggplot(df_shapes, aes(0, 0, shape = shape)) +
geom_point(aes(shape = shape), size = 5, fill = 'red') +
scale_shape_identity() +
facet_wrap(~shape) +
theme_void()
df_shapes <- data.frame(shape = 0:24)
ggplot(df_shapes, aes(0, 0, shape = shape)) +
geom_point(aes(shape = shape), size = 5, fill = 'red') +
scale_shape_identity() +
facet_wrap(~shape) +
theme_void()
df_shapes
ggplot(df_shapes, aes(shape = shape)) + geom_point()
ggplot(df_shapes, aes(0, 0, shape = shape)) + geom_point(aes(shape = shape))
ggplot(df_shapes, aes(0, 0, shape = df_shapes$shape)) + geom_point(aes(shape = df_shapes$shape))
ggplot(df_shapes, aes(0, 0, shape = factor(df_shapes$shape))) + geom_point(aes(shape = factor(df_shapes$shape)))
titanic <- read.csv(paste("http://biostat.mc.vanderbilt.edu/",
+ "wiki/pub/Main/",
+ "DataSets/titanic3.csv", sep = ""))
titanic <- read.csv(paste("http://biostat.mc.vanderbilt.edu/",
"wiki/pub/Main/",
"DataSets/titanic3.csv", sep = ""))
data("Titanic")
data("Titanic")
str(Titanic)
library(plyr)
td <- ddply(Titanic, c("Class", "Age", "Sex"), summarize, ps = length(Survived[Survived == "Yes"])/length(Survived))
td <- ddply(Titanic, c("Class", "Age", "Sex"), summarize)
td <- ddply(Titanic, c(Class, Age, Sex), summarize)
td <- ddply(Titanic, c(Titanic$Class, Titanic$Age, Titanic$Sex), summarize)
Titanic$ps = length(Survived[Survived == "Yes"])/length(Survived)
Titanic$ps = length(Titanic$Survived[Titanic$Survived == "Yes"])/length(Titanic$Survived)
Survived <- Titanic$Survived
Survived <- Titanic["Survived"]
Titanic$ps = length(Survived[Survived == "Yes"])/length(Survived)
p8 <- ggplot(Titanic, aes(x = Age, y = ps))
data.frame(Titanic)
p8 <- ggplot(Titanic, aes(x = Age, y = ps))
Titanic
data("Titanic")
str(Titanic)
Titanic["Survived"]
Titanic[1:4]
Titanic[1:4][1:2]
Titanic[1:4, 1:2]
Titanic
Titanic$Age
Titanic[Age]
Titanic["Age"]
install.packages("titanic")
install.packages("Rtools")
library(titanic)
knitr::kable(head(titanic_train))
titanic_train
str(titanic_train)
titanic_train$age.g = as.integer(cut(titanic_train$Age, 10))
td <- ddply(titanic_train, c("Pclass", "age.g", "Sex"), ps = length(Survived[Survived == 1])/length(Survived))
p8 <- ggplot(td, aes(x = age.g, y = ps))
p8 + geom_point()
td
str(td)
td <- ddply(titanic_train, c("Pclass", "age.g", "Sex"), ps = length(Survived[Survived == 1])/length(Survived))
td$ps = length(Survived[Survived == 1])/length(Survived)
Survived = td$Survived
td$ps = length(Survived[Survived == 1])/length(Survived)
str(td)
p8 <- ggplot(td, aes(x = age.g, y = ps))
p8 + geom_point()
p8 <- ggplot(td, aes(x = age.g, y = Sex))
p8
p8 <- ggplot(td, aes(x = Age, y = Sex))
p8
p8 + geom_point()
p8 <- ggplot(td, aes(x = age.g, y = Sex))
p8 + geom_point()
p8 + geom_point() + facet_grid(Sex ~ Pclass)
p8 <- ggplot(td, aes(x = age.g, y = Survived))
p8 + geom_point() + facet_grid(Sex ~ Pclass)
p8 + geom_point(stat = "identity") + facet_grid(Sex ~ Pclass)
p9 <- p8 + geom_point(stat = "identity") + facet_grid(Sex ~ Pclass)
p9 + scale_y_discrete(breaks = c("1", "2"), labels = c("Yes", "No"))
p9 + scale_y_continuous(breaks = c("1", "2"), labels = c("Yes", "No"))
p9 + scale_y_continuous(breaks = c(0, 1), labels = c("Yes", "No"))
p9 + scale_y_continuous(breaks = c(1, 0), labels = c("Yes", "No"))
p9 + scale_y_continuous(breaks = c("1", "0"), labels = c("Yes", "No"))
p9 + scale_y_continuous(breaks = c(1, 0), labels = c("Yes", "No"))
p9 + scale_y_continuous(breaks = c(1, 0), labels = c("Yes", "No")) + theme_classic()
p9 + scale_y_continuous(breaks = c(1, 0), labels = c("Yes", "No")) + theme_gray()
p9 + scale_y_continuous(breaks = c(1, 0), labels = c("Yes", "No")) + theme_linedraw()
p9 + scale_y_continuous(breaks = c(1, 0), labels = c("Yes", "No")) + theme_bw()
savehistory("C:/Users/S K Nayak/Documents/Misc-VIT/MAT2001-Stat/labwork.r")
