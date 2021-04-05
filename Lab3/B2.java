package com.company;

import java.util.*;

public class Main {
    public static class Stock {
        int fir, sec, sold;
        public Stock(int f, int s) {
            fir = f;
            sec = s;
            sold = 0;
        }
    }
    public static class The_Comparator implements Comparator<Stock> {
        public int compare(Stock s1, Stock s2) {
            int p1 = s1.sec * (s1.sold + 1) - s1.fir * (s1.sold + 1) * (s1.sold + 1) - s1.sec * s1.sold + s1.fir * s1.sold * s1.sold;
            int p2 = s2.sec * (s2.sold + 1) - s2.fir * (s2.sold + 1) * (s2.sold + 1) - s2.sec * s2.sold + s2.fir * s2.sold * s2.sold;
            return p2 - p1;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int b = input.nextInt();

        PriorityQueue<Stock> pQueue = new PriorityQueue<Stock>(new The_Comparator());
        for (int k = 0; k < n; k++) {
            int a = input.nextInt();
            int c = input.nextInt();
            Stock st = new Stock(-1 * a, c);
            pQueue.add(st);
        }
        long sum = 0;
        for (int i = 0; i < b; i++) {
            Stock s1 = pQueue.poll();
            int profit = s1.sec * (s1.sold + 1) - s1.fir * (s1.sold + 1) * (s1.sold + 1) - s1.sec * s1.sold + s1.fir * s1.sold * s1.sold;
            if (profit > 0) {
                sum += profit;
                s1.sold += 1;
                pQueue.add(s1);
            } else {
                break;
            }
        }
        System.out.println(sum);
    }

}
