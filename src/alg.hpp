





/*
 * 
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 
 * */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list_1=l1;
        ListNode* list_2=l2;

        int depth_of_list_1=1;
        int depth_of_list_2=1;

        cout<<"the depth_of_list_1 and the depth_of_list_2 is :"
            <<depth_of_list_1<<" "<<depth_of_list_2<<endl;

        //tail_node should point to tail of larger list;
        ListNode* head_node = depth_of_list_1 > depth_of_list_2 ? l1 : l2;
        //larger list
        ListNode* larger_list = depth_of_list_1 > depth_of_list_2 ? l1 : l2;
        // if list_1 larger than list_2;
        if(depth_of_list_1>depth_of_list_2){
            while( l1 && l2 ){
                l1->val+=l2->val;
                cout<<"l1->val+=l2->val;"<< l1->val <<endl;
                l1=l1->next;
                l2=l2->next;
            }
        }else{
            while( l1 && l2 ){
                l2->val+=l1->val;      
                cout<<"l2->val+=l1->val;    "<< l2->val <<endl;
                l1=l1->next;
                l2=l2->next;
            }
        }
        
    

        while(1){
            cout<<"loop , head_node value is "<<head_node->val<<endl;
            if(head_node->val>= 10){
                cout<<"need rounding up "<<endl;
                head_node->val-=10;
                ListNode* nextNode = head_node->next;
                if(nextNode){
                    nextNode->val+=1;
                    head_node=nextNode;
                }else{
                    nextNode=new ListNode(1);
                    head_node->next=nextNode;
                    return larger_list;
                }
            }else{
                if(head_node->next)
                    head_node=head_node->next;
                else 
                    return larger_list;
            }
        }
        return larger_list;
    }
    ListNode* __get_parent(ListNode* list,ListNode* node){
        if(list==node)
            return nullptr;
        
        ListNode* n = list;
        while(n){
            if(n->next == node)
                return n;
            n=n->next;
        }
        return nullptr;
    }
    ListNode* fail_01(ListNode* l1,ListNode*l2){
        unsigned long long sum1=0;
        unsigned long long sum2=0;;
        unsigned long long multi_factor =1;
        while(l1){
            if(l1->val==0){
                //sum1*=10;
            }else{
                //l1->val!=0
                sum1+=(long long)l1->val*(long long)multi_factor;
            }
            multi_factor*=10;
            l1=l1->next;
        }
        multi_factor=1;
        while(l2){
            if(l2->val==0){
                //sum2*=10;
            }else{
                //l1->val!=0
                sum2+=(long long )l2->val*(long long)multi_factor;
            }
            multi_factor*=10;
            l2=l2->next;
        }
        cout<<"sum 1 and sum2 :"<<sum1 <<" "<<sum2<<endl;

        long long sum = sum1+ sum2;
        long long sum0=sum;
        cout<<sum<<endl;
        int digit_num=0;
        while(sum0!=0){
            sum0/=10;
            ++digit_num;
        }
        if(digit_num==0)
            digit_num=1;
            

        ListNode* last_node=nullptr;
        ListNode* firt_node=nullptr;
        for(int i=0;i<digit_num;++i){
            int digit= __get_digit(sum,i);
            cout<<digit;
            ListNode* node = new ListNode(digit);
            if(i==0)
                firt_node=node;
            if(last_node!=nullptr)
                last_node->next=node;
            last_node=node;
            if(i+1==digit_num)
                return firt_node;
        }
        return nullptr;
    }
    long long __get_digit(long long sum,long long num){
        long long n=1;
        for(int i=0;i<num;++i){
            n*=10;
        }
        return (sum/n) %10;
    }
};


//3. Longest Substring Without Repeating Characters
class Solution_longest_substring {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1)
            return 1;
        std::set<char> set;
        std::set<char> set2;
        for(int i=0;i<s.size();++i){
            if(set.find(s[i]) !=set.end()){
                if(set.size()> set2.size())
                    std::swap(set,set2);
                set.clear();
                for(int i2=i-1;i2>=0;--i2){
                    if(s[i2]==s[i])
                        break;
                    if(s[i2]!=s[i])
                        set.insert(s[i2]);
                }
                i--;
            }
            else{
                set.insert(s[i]);
               
            }
        }

        cout<<"set :"<<endl;
        for(auto e: set)
            cout<<e<<" ";

        cout<<endl;
        cout<<"set2:"<<endl;
        for(auto e:set2)
            cout<<e<<" ";

        if(set2.size() < set.size())
            return set.size();
        return set2.size();
    }
    int __get_last_same_char_index(string s,char c,int i){
        cout<<"string is :"<<s<<", c:"<<c<<endl;
        for(int i=i-1;i>=0;--i){
            if(s[i]==c)
                return i;
        }
        return 0;
    }
};

// 4. Median of Two Sorted Arrays
class Solution_median_of_two_sorted_arrays {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> v = __get_consolidation(nums1,nums2);
        for(auto e: v)
            cout<<e<<" ";

        bool is_odd = (v.size()%2)==0 ? true : false;
        if(is_odd){
            cout<<"is odd"<<endl;
            int mid = v.size()/2;
            double result = ((double)(v[mid-1]+v[mid]) )/2;
            return result;
        }else{
            cout<<"not odd"<<endl;
            int mid = v.size()/2;
            return v[mid];
        }
    }


    vector<int> __get_consolidation(vector<int>& nums1,vector<int>& nums2){
        vector<int> consolidation;
        int i=0;
        int j=0;
        while(i!=nums1.size() || j!=nums2.size() ){
            if(i==nums1.size()){
                consolidation.push_back(nums2[j]);
                j++;
            }
            else if (j==nums2.size()){
                consolidation.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j] ){
                consolidation.push_back(nums2[j]);
                j++;
            }else{
                //nums1[i] < num
                consolidation.push_back(nums1[i]);
                i++;
            }

        }
        return consolidation;
    }
};



//5. Longest Palindromic Substring
class Solution_Longest_Palindromic_substring {
public:
    string longestPalindrome(string s) {
        int length=0;
        int begin_index;
        int end_index;
        bool is_palindromic=false;
        for(int i=0;i<s.size();++i){
            for(int i2=i+1;i2<s.size();++i2){
                if(__is_palindromic(s,i,i2)){
                    if((i2-i+1) > length){
                        begin_index=i;
                        end_index=i2;
                        length=(i2-i+1);
                    }
                    is_palindromic=true;
                }
            }
        }
     
        if(is_palindromic){
                cout<<"begin char is :"<<s[begin_index]<<" begin_index :"<<begin_index;
                        cout<<" end char is :"<<s[end_index]<<" end_index :"<<end_index<<endl;
                        std::string s_=s.substr(begin_index,(end_index-begin_index)+1);
                        cout<<"substr string is :"<<s_<<endl;
                        return s_;
        }

        return std::string(s.c_str(),1);
    }

    //memory limit exceed in lettcode if `string s`
    bool __is_palindromic(string s,int begin_index,int end_index){
       
        for(int i=0;begin_index<end_index;++i){
            
   
            if(s[begin_index]!=s[end_index])
                return false;

            begin_index++;
            end_index--;
        }
        return true;
    }
};


//6. Zigzag Conversion
class Solution_zigzag_conversion {
public:
    string convert(string s, int numRows) {
     if(numRows<=1)   
        return s;
    std::vector<std::string> list(numRows,"");
    int currentline=0;
    bool reachedEdge=true;
    for(int i=0;i<s.length();++i){
        if(currentline==0 || currentline==list.size()-1){
            reachedEdge=!reachedEdge;
        }
        list.at(currentline) +=s.at(i);
        if(!reachedEdge){
            currentline++;
        }else{
            currentline--;
        }
    }
    std::string result="";
    for(auto str: list){
        result+=str;
    }
    return result;
    }
};

//7. Reverse Integer
class Solution_reverse_integer {
public:
    int reverse(int x) {
        long x1=(long)x;
        int a= -pow(2, 31);
        if(x1>= pow(2, 31) - 1 || x1<= a)
            return 0;

        if(x<10 && x>-10)
            return x;
        
        cout<<"x greater than 10"<<endl;
        bool is_zheng=x1>0? true:false;
        if(!is_zheng)
            x1=-x1;
        int ditgit_num = __get_ditgit_num(x1);

        int multi_factor=ditgit_num-1;

        std::vector<long> v;
        for(int i=0;i<ditgit_num;++i){
            int num = (x1/__m_num(i)) % 10;
            v.push_back(num);
        }
        long result=0;
        for(auto e : v){
            cout<<e<<" ";
            result+=e*__m_num(multi_factor);
            multi_factor--;        
        }
        if(result>= pow(2, 31) - 1 || result<= a)
            return 0;
        if(!is_zheng){
            result=-result;
        }
            
        return result;
    }
    int __m_num(int n){
        int num=1;
        while(n!=0){
            num*=10;
            n--;
        }
        return num;
        
    }
    int __get_ditgit_num(int x){
        int digit_num=0;
        while(x!=0){

            x/=10;
            digit_num++;
        }
        return digit_num;
    }
    
};
