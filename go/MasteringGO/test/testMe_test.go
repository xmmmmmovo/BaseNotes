package main

import "testing"

func Test_f1(t *testing.T) {
	type args struct {
		n int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := f1(tt.args.n); got != tt.want {
				t.Errorf("f1() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_f2(t *testing.T) {
	type args struct {
		n int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := f2(tt.args.n); got != tt.want {
				t.Errorf("f2() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_s1(t *testing.T) {
	type args struct {
		s string
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := s1(tt.args.s); got != tt.want {
				t.Errorf("s1() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_s2(t *testing.T) {
	type args struct {
		s string
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := s2(tt.args.s); got != tt.want {
				t.Errorf("s2() = %v, want %v", got, tt.want)
			}
		})
	}
}
