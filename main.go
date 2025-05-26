package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"os"
	"strconv"
	"strings"
)

type Student struct {
	Name string `json:"name"`
	Age  int    `json:"age"`
}

var Students = map[int]Student{}

func StudentInit() {
	Students[1] = Student{"Bob", 27}
	Students[2] = Student{"Asa", 18}
	Students[3] = Student{"Eve", 29}
	Students[4] = Student{"Yao", 25}
	Students[5] = Student{"Ben", 30}
}
func Home(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Http serv \n about /about")
}
func About(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "About")
}
func Weird(w http.ResponseWriter, r *http.Request) {
	image, err := os.ReadFile("ass.jpg")
	if err != nil {
		panic(err)
	}
	w.Header().Set("Content-Type", "image/jpeg")
	w.Write(image)
}
func StudentHandle(w http.ResponseWriter, r *http.Request) {
	switch r.Method {
	case http.MethodPost:
		defer r.Body.Close()
		body, err := io.ReadAll(r.Body)
		if err != nil {
			http.Error(w, "json Err", http.StatusRequestTimeout)
			return
		}
		if !json.Valid(body) {
			http.Error(w, "json Err", http.StatusBadRequest)
		}
		var st Student
		err = json.Unmarshal(body, &st)
		if err != nil {
			http.Error(w, "json Err", http.StatusBadRequest)
		}
		Students[12] = st
		fmt.Println("Write down", st)
		w.WriteHeader(http.StatusCreated)

	default:
		http.Error(w, "Method not available", http.StatusMethodNotAllowed)
	}
}
func StudentsHandle(w http.ResponseWriter, r *http.Request) {
	pathParts := strings.Split(r.URL.Path, "/")
	if len(pathParts) < 3 {
		http.Error(w, "invalid path", http.StatusBadRequest)
		return
	}
	id, err := strconv.Atoi(pathParts[2])
	if err != nil {
		http.Error(w, "Invalid ID", http.StatusBadRequest)
		return
	}
	switch r.Method {
	case http.MethodGet:
		w.Header().Set("Content-Type", "application/json")
		st, ok := Students[id]
		if !ok {
			http.Error(w, "Invalid ID", http.StatusBadRequest)
			return
		}
		data, err := json.Marshal(st)
		if err != nil {
			http.Error(w, "json Err", http.StatusRequestTimeout)
			return
		}
		w.Write(data)
		fmt.Println("Обработка", st)
	case http.MethodDelete:
		st, ok := Students[id]
		if !ok {
			http.Error(w, "Invalid ID", http.StatusBadRequest)
			return
		}
		fmt.Println("Deleted student ", st)
		delete(Students, id)
	case http.MethodPatch:

	default:
		http.Error(w, "Method not available", http.StatusMethodNotAllowed)
	}
}
func main() {
	StudentInit()
	http.HandleFunc("/", Home)
	http.HandleFunc("/about", About)
	http.HandleFunc("/Weird", Weird)
	http.HandleFunc("/students", StudentHandle)
	http.HandleFunc("/students/", StudentsHandle)

	fmt.Println("start")
	err := http.ListenAndServe("localhost:8080", nil)
	if err != nil {
		panic(err)
	}

}
