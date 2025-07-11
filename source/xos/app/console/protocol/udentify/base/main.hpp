//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2024 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 10/21/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_UDENTIFY_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_UDENTIFY_BASE_MAIN_HPP

#include "xos/app/console/protocol/udentify/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace udentify {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::udentify::base::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    typedef typename extends::sequence_char_t sequence_char_t;
    typedef typename extends::char_sequence_t char_sequence_t;
    typedef typename extends::char_seeker_t char_seeker_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_writer_t char_writer_t;
    typedef typename extends::reader_string_t reader_string_t;
    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::literal_string_t literal_string_t;

    typedef typename extends::to_json_node_t to_json_node_t;
    typedef typename extends::json_node_t json_node_t;

    /// constructor / destructor
    maint()
    : run_(0), 

      udentity_path_("udentity"),
      
      nameof_udentify_user_("user"), 
      nameof_udentify_resource_("resource"), 
      nameof_udentify_password_("password"),

      default_udentify_user_(nameof_udentify_user_), 
      default_udentify_resource_(nameof_udentify_resource_), 
      default_udentify_password_(nameof_udentify_password_),

      udentify_user_(default_udentify_user_), 
      udentify_resource_(default_udentify_resource_), 
      udentify_password_(default_udentify_password_),

      begin_udentify_resource_("\",\"resource\":\""), 
      begin_udentify_password_("\",\"password\":\""),
      begin_udentify_message_("{\"password\":{\"user\":\""), 
      endof_udentify_message_("\"}}"),

      begin_udentify_response_message_("{\"password\":\""), 
      endof_udentify_response_message_("\"}") {
        set_udentify_request_message();
        set_udentify_response_message();
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    //////////////////////////////////////////////////////////////////////////
    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ...output_user_run
    virtual int default_output_user_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& output = this->udentify_user();
        if ((output_lf)) {
            this->outln(output);
        } else {
            this->out(output);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_resource_run
    virtual int default_output_resource_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& output = this->udentify_resource();
        if ((output_lf)) {
            this->outln(output);
        } else {
            this->out(output);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_password_run
    virtual int default_output_password_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& output = this->udentify_password();
        if ((output_lf)) {
            this->outln(output);
        } else {
            this->out(output);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_default_user_run
    virtual int default_output_default_user_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& output = this->default_udentify_user();
        if ((output_lf)) {
            this->outln(output);
        } else {
            this->out(output);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_default_resource_run
    virtual int default_output_default_resource_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& output = this->default_udentify_resource();
        if ((output_lf)) {
            this->outln(output);
        } else {
            this->out(output);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_default_password_run
    virtual int default_output_default_password_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool& output_lf = this->output_lf();
        const string_t& output = this->default_udentify_password();
        if ((output_lf)) {
            this->outln(output);
        } else {
            this->out(output);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...nameof_udentify_user
    virtual string_t& set_nameof_udentify_user(const string_t& to) {
        string_t& nameof_udentify_user = this->nameof_udentify_user();
        nameof_udentify_user.assign(to);
        return nameof_udentify_user;
    }
    virtual string_t& set_nameof_udentify_user(const char_t* to) {
        string_t& nameof_udentify_user = this->nameof_udentify_user();
        nameof_udentify_user.assign(to);
        return nameof_udentify_user;
    }
    virtual string_t& nameof_udentify_user() const {
        return (string_t&)nameof_udentify_user_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...nameof_udentify_resource
    virtual string_t& set_nameof_udentify_resource(const string_t& to) {
        string_t& nameof_udentify_resource = this->nameof_udentify_resource();
        nameof_udentify_resource.assign(to);
        return nameof_udentify_resource;
    }
    virtual string_t& set_nameof_udentify_resource(const char_t* to) {
        string_t& nameof_udentify_resource = this->nameof_udentify_resource();
        nameof_udentify_resource.assign(to);
        return nameof_udentify_resource;
    }
    virtual string_t& nameof_udentify_resource() const {
        return (string_t&)nameof_udentify_resource_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...nameof_udentify_password
    virtual string_t& set_nameof_udentify_password(const string_t& to) {
        string_t& nameof_udentify_password = this->nameof_udentify_password();
        nameof_udentify_password.assign(to);
        return nameof_udentify_password;
    }
    virtual string_t& set_nameof_udentify_password(const char_t* to) {
        string_t& nameof_udentify_password = this->nameof_udentify_password();
        nameof_udentify_password.assign(to);
        return nameof_udentify_password;
    }
    virtual string_t& nameof_udentify_password() const {
        return (string_t&)nameof_udentify_password_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...default_udentify_user
    virtual string_t& set_default_udentify_user(const string_t& to) {
        string_t& default_udentify_user = this->default_udentify_user();
        default_udentify_user.assign(to);
        return set_udentify_user(to);
    }
    virtual string_t& set_default_udentify_user(const char_t* to) {
        string_t& default_udentify_user = this->default_udentify_user();
        default_udentify_user.assign(to);
        return set_udentify_user(to);
    }
    virtual string_t& default_udentify_user() const {
        return (string_t&)default_udentify_user_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...default_udentify_resource
    virtual string_t& set_default_udentify_resource(const string_t& to) {
        string_t& default_udentify_resource = this->default_udentify_resource();
        default_udentify_resource.assign(to);
        return set_udentify_resource(to);
    }
    virtual string_t& set_default_udentify_resource(const char_t* to) {
        string_t& default_udentify_resource = this->default_udentify_resource();
        default_udentify_resource.assign(to);
        return set_udentify_resource(to);
    }
    virtual string_t& default_udentify_resource() const {
        return (string_t&)default_udentify_resource_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...default_udentify_password
    virtual string_t& set_default_udentify_password(const string_t& to) {
        string_t& default_udentify_password = this->default_udentify_password();
        default_udentify_password.assign(to);
        return set_udentify_password(to);
    }
    virtual string_t& set_default_udentify_password(const char_t* to) {
        string_t& default_udentify_password = this->default_udentify_password();
        default_udentify_password.assign(to);
        return set_udentify_password(to);
    }
    virtual string_t& default_udentify_password() const {
        return (string_t&)default_udentify_password_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_user
    virtual string_t& set_udentify_user(const string_t& to) {
        string_t& udentify_user = this->udentify_user();
        udentify_user.assign(to);
        return udentify_user;
    }
    virtual string_t& set_udentify_user(const char_t* to) {
        string_t& udentify_user = this->udentify_user();
        udentify_user.assign(to);
        return udentify_user;
    }
    virtual string_t& udentify_user() const {
        return (string_t&)udentify_user_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_resource
    virtual string_t& set_udentify_resource(const string_t& to) {
        string_t& udentify_resource = this->udentify_resource();
        udentify_resource.assign(to);
        return udentify_resource;
    }
    virtual string_t& set_udentify_resource(const char_t* to) {
        string_t& udentify_resource = this->udentify_resource();
        udentify_resource.assign(to);
        return udentify_resource;
    }
    virtual string_t& udentify_resource() const {
        return (string_t&)udentify_resource_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_password
    virtual string_t& set_udentify_password(const string_t& to) {
        string_t& udentify_password = this->udentify_password();
        udentify_password.assign(to);
        return udentify_password;
    }
    virtual string_t& set_udentify_password(const char_t* to) {
        string_t& udentify_password = this->udentify_password();
        udentify_password.assign(to);
        return udentify_password;
    }
    virtual string_t& udentify_password() const {
        return (string_t&)udentify_password_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...begin_udentify_resource
    virtual string_t& set_begin_udentify_resource(const string_t& to) {
        string_t& begin_udentify_resource = this->begin_udentify_resource();
        begin_udentify_resource.assign(to);
        return begin_udentify_resource;
    }
    virtual string_t& set_begin_udentify_resource(const char_t* to) {
        string_t& begin_udentify_resource = this->begin_udentify_resource();
        begin_udentify_resource.assign(to);
        return begin_udentify_resource;
    }
    virtual string_t& begin_udentify_resource() const {
        return (string_t&)begin_udentify_resource_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...begin_udentify_password
    virtual string_t& set_begin_udentify_password(const string_t& to) {
        string_t& begin_udentify_password = this->begin_udentify_password();
        begin_udentify_password.assign(to);
        return begin_udentify_password;
    }
    virtual string_t& set_begin_udentify_password(const char_t* to) {
        string_t& begin_udentify_password = this->begin_udentify_password();
        begin_udentify_password.assign(to);
        return begin_udentify_password;
    }
    virtual string_t& begin_udentify_password() const {
        return (string_t&)begin_udentify_password_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...begin_udentify_message
    virtual string_t& set_begin_udentify_message(const string_t& to) {
        string_t& begin_udentify_message = this->begin_udentify_message();
        begin_udentify_message.assign(to);
        return begin_udentify_message;
    }
    virtual string_t& set_begin_udentify_message(const char_t* to) {
        string_t& begin_udentify_message = this->begin_udentify_message();
        begin_udentify_message.assign(to);
        return begin_udentify_message;
    }
    virtual string_t& begin_udentify_message() const {
        return (string_t&)begin_udentify_message_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...endof_udentify_message
    virtual string_t& set_endof_udentify_message(const string_t& to) {
        string_t& endof_udentify_message = this->endof_udentify_message();
        endof_udentify_message.assign(to);
        return endof_udentify_message;
    }
    virtual string_t& set_endof_udentify_message(const char_t* to) {
        string_t& endof_udentify_message = this->endof_udentify_message();
        endof_udentify_message.assign(to);
        return endof_udentify_message;
    }
    virtual string_t& endof_udentify_message() const {
        return (string_t&)endof_udentify_message_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...begin_udentify_response_message
    virtual string_t& set_begin_udentify_response_message(const string_t& to) {
        string_t& begin_udentify_response_message = this->begin_udentify_response_message();
        begin_udentify_response_message.assign(to);
        return begin_udentify_response_message;
    }
    virtual string_t& set_begin_udentify_response_message(const char_t* to) {
        string_t& begin_udentify_response_message = this->begin_udentify_response_message();
        begin_udentify_response_message.assign(to);
        return begin_udentify_response_message;
    }
    virtual string_t& begin_udentify_response_message() const {
        return (string_t&)begin_udentify_response_message_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...endof_udentify_response_message
    virtual string_t& set_endof_udentify_response_message(const string_t& to) {
        string_t& endof_udentify_response_message = this->endof_udentify_response_message();
        endof_udentify_response_message.assign(to);
        return endof_udentify_response_message;
    }
    virtual string_t& set_endof_udentify_response_message(const char_t* to) {
        string_t& endof_udentify_response_message = this->endof_udentify_response_message();
        endof_udentify_response_message.assign(to);
        return endof_udentify_response_message;
    }
    virtual string_t& endof_udentify_response_message() const {
        return (string_t&)endof_udentify_response_message_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_request_message
    virtual string_t& set_udentify_request_message() {
        const string_t& udentify_user = this->udentify_user();
        const string_t& udentify_resource = this->udentify_resource();
        const string_t& udentify_password = this->udentify_password();
        const string_t& begin_udentify_resource = this->begin_udentify_resource();
        const string_t& begin_udentify_password = this->begin_udentify_password();
        const string_t& begin_udentify_message = this->begin_udentify_message();
        const string_t& endof_udentify_message = this->endof_udentify_message();
        string_t& udentify_request_message = this->udentify_request_message();
        udentify_request_message.assign(begin_udentify_message);
        udentify_request_message.append(udentify_user);
        udentify_request_message.append(begin_udentify_resource);
        udentify_request_message.append(udentify_resource);
        udentify_request_message.append(begin_udentify_password);
        udentify_request_message.append(udentify_password);
        udentify_request_message.append(endof_udentify_message);
        return udentify_request_message;
    }
    virtual string_t& set_udentify_request_message(const string_t& to) {
        string_t& udentify_request_message = this->udentify_request_message();
        udentify_request_message.assign(to);
        return udentify_request_message;
    }
    virtual string_t& set_udentify_request_message(const char_t* to) {
        string_t& udentify_request_message = this->udentify_request_message();
        udentify_request_message.assign(to);
        return udentify_request_message;
    }
    virtual string_t& udentify_request_message() const {
        return (string_t&)udentify_request_message_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...udentify_response_message
    virtual string_t& set_udentify_response_message() {
        const string_t& udentify_password = this->udentify_password();
        const string_t& begin_udentify_response_message = this->begin_udentify_response_message();
        const string_t& endof_udentify_response_message = this->endof_udentify_response_message();
        string_t& udentify_response_message = this->udentify_response_message();
        udentify_response_message.assign(begin_udentify_response_message);
        udentify_response_message.append(udentify_password);
        udentify_response_message.append(endof_udentify_response_message);
        return udentify_response_message;
    }
    virtual string_t& set_udentify_response_message(const string_t& to) {
        string_t& udentify_response_message = this->udentify_response_message();
        udentify_response_message.assign(to);
        return udentify_response_message;
    }
    virtual string_t& set_udentify_response_message(const char_t* to) {
        string_t& udentify_response_message = this->udentify_response_message();
        udentify_response_message.assign(to);
        return udentify_response_message;
    }
    virtual string_t& udentify_response_message() const {
        return (string_t&)udentify_response_message_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...udentity_path
    virtual string_t& set_udentity_path(const string_t& to) {
        string_t& udentity_path = this->udentity_path();
        udentity_path.assign(to);
        return udentity_path;
    }
    virtual string_t& set_udentity_path(const char_t* to) {
        string_t& udentity_path = this->udentity_path();
        udentity_path.assign(to);
        return udentity_path;
    }
    virtual string_t& udentity_path() const {
        return (string_t&)udentity_path_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...request
    virtual string_t& request() const {
        return udentify_request_message();
    }
    /// ...response
    virtual string_t& response() const {
        return udentify_response_message();
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t udentity_path_, 
             nameof_udentify_user_, nameof_udentify_resource_, nameof_udentify_password_,
             default_udentify_user_, default_udentify_resource_, default_udentify_password_,
             udentify_user_, udentify_resource_, udentify_password_,
             begin_udentify_resource_, begin_udentify_password_,
             begin_udentify_message_, endof_udentify_message_, 
             udentify_request_message_, udentify_response_message_, 
             begin_udentify_response_message_, endof_udentify_response_message_; 
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace udentify 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_UDENTIFY_BASE_MAIN_HPP

