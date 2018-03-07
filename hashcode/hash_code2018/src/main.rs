#![allow(non_snake_case)]


use std::io;

macro_rules! parse_line {
    ($($t: ty),+) => ({
        let mut a_str = String::new();
        io::stdin().read_line(&mut a_str).expect("read error");
        let mut a_iter = a_str.split_whitespace();
        (
            $(
            a_iter.next().unwrap().parse::<$t>().expect("parse error"),
            )+
        )
    })
}

struct Ride {
    a: i32,
    b: i32,
    x: i32,
    y: i32,
    s: i32,
    f: i32,
    id: usize,
    len: i32,
    done: bool,
}

struct Car {
    x: i32,
    y: i32,
    t: i32,
}

fn dist(a: i32, b: i32, x: i32, y: i32) -> i32 {
    let (d1, d2) = (a - x, b - y);
    d1.abs() + d2.abs()
}

fn main() {
    let (R, C, F, N, B, T) = parse_line!(i32, i32, usize, usize, i32, i32);
    let mut rides = Vec::new();
    for i in 0usize..N {
        let (a, b, x, y, s, f) = parse_line!(i32, i32, i32, i32, i32, i32);
        rides.push(Ride { a: a, b: b, x: x, y: y, s: s, f: f, id: i, 
            len: dist(a, b, x, y), done: false });
    }
    rides.sort_by(|a, b| {
        let x = a.s;
        let y = b.s;
        x.cmp(&y) 
    });
    /*for i in 0usize..N {
        println!("{} {}", rides[i].id, rides[i].s);
    }*/
    let mut res = vec![vec![0; 0]; F];
    let mut cars = Vec::new();
    for _i in 0usize..F {
        cars.push(Car { x: 0, y: 0, t: 0});
    }
    for _it in 0usize..N {
        let mut bst_f_ind: i32 = -1;
        let mut bst_n_ind: i32 = -1;
        let mut bst_cost: i32 = 0; 
        for i in 0usize..N {
            if rides[i].done {
                continue;
            }
            for j in 0usize..F {
                let len = dist(cars[j].x, cars[j].y, rides[i].a, rides[i].b);
                let earliest_f = cars[j].t + len + rides[i].len;
                if earliest_f <= rides[i].f {
                    let earliest_s = cars[j].t + len;

                    /*
                    // time too early for ride.s --> you have to wait
                    let cost1 = std::cmp::max(0, rides[i].s - earliest_s);
                    // distance car to ride begin
                    let cost2 = len;
                    // time too late for ride.s
                    let cost3 = std::cmp::max(0, earliest_s - rides[i].s);
                    // ride length
                    let cost4 = rides[i].len;

                    // weigh time you have to wait high for C, D
                    // weigh time you are too late high for B, E
                    let mut cost = 5 * cost1 + 2 * cost2 + 10000 * cost3 + 0 * cost4;
                    if cost3 == 0 {
                        cost -= B
                    }
                    if bst_f_ind == -1 || cost < bst_cost {
                        bst_f_ind = j as i32;
                        bst_n_ind = i as i32;
                        bst_cost = cost;
                    }
                    */

                    // code for D high score
                    // just take earliest starting ride
                    // if not late, penalize ride taking you far 
                    let mut take_time = std::cmp::max(earliest_s, rides[i].s);
                    if earliest_f <= (T as f64 * 0.98) as i32 {
                        take_time += rides[i].len / 15;
                    }
                    if bst_f_ind == -1 || take_time < bst_cost {
                        bst_f_ind = j as i32;
                        bst_n_ind = i as i32;
                        bst_cost = take_time;
                    }
                }
            }
        }
        if bst_f_ind != -1 {
            let j = bst_f_ind as usize;
            let i = bst_n_ind as usize;
            res[j].push(rides[i].id);
            let len = dist(cars[j].x, cars[j].y, rides[i].a, rides[i].b);
            cars[j].t = std::cmp::max(cars[j].t + len + rides[i].len, 
                                      rides[i].s + rides[i].len);
            cars[j].x = rides[i].x;
            cars[j].y = rides[i].y;
            rides[i].done = true;
        }
    }
    for i in 0usize..F {
        print!("{}", res[i].len());
        for j in &res[i] {
            print!(" {}", j);
        }
        print!("\n");
    }
}
