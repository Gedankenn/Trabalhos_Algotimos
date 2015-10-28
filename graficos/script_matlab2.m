%% 

close all;
clear all;
clc;

%% Import
data = csvread('C:\Users\gedan\Documents\trabalho-algoritimos\algoritimos2\teste1.csv',1,0);

Tamanho = data(:,1);
ordenacao(:,1) = data(:,2);
ordenacao(:,2) = data(:,5);
ordenacao(:,3) = data(:,8);
jaordenado(:,1) = data(:,3);
jaordenado(:,2) = data(:,6);
jaordenado(:,3) = data(:,9);
decrescente(:,1) = data(:,4);
decrescente(:,2) = data(:,7);
decrescente(:,3) = data(:,10);

clear data;

%% Graficos

plot(Tamanho,ordenacao,'LineWidth',2);
legend('Quicksort','Mergesort','bublesort');
grid on;
title('Tempo de ordenacao');
ylabel('Tempo [s]');
xlabel('Tamanho do vetor');

figure;
plot(Tamanho,jaordenado,'LineWidth',2);
legend('Quicksort','Mergesort','bublesort');
grid on;
title('Tempo ja ordenado');
ylabel('Tempo [s]');
xlabel('Tamanho do vetor');

figure;
plot(Tamanho,decrescente,'LineWidth',2);
legend('Quicksort','Mergesort','bublesort');
grid on;
title('Tempo de decresnte');
ylabel('Tempo [s]');
xlabel('Tamanho do vetor');

%xlim([-10000 10^7])

% figure;
% subplot(2,1,1);
% plot(Tamanho,jaordenado,'LineWidth',2);
% legend('Quicksort legend','Mergesort','bublesort');
% grid on;
% title('Tempo de ordenacao');
% ylabel('Tempo de ordenacao [s]');
% xlabel('Tamanho do vetor');
% 
% subplot(212);
% plot(Tamanho,decrescente,'-.','LineWidth',2);
% legend('Quicksort ja ordenado','Mergesort','Heapsort','Shellsort','Quicksort Decrescente','Mergesort','Heapsort','Shellsort');
% grid on;
% title('Tempo de ordenacao');
% ylabel('Tempo [s]');
% xlabel('Tamanho do vetor');